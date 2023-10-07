import pandas as pd
#import matplotlib.pyplot as plt
import numpy as np
from sklearn.model_selection import train_test_split as tts
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import confusion_matrix, classification_report, accuracy_score
#from sklearn.manifold import TSNE
from sklearn.feature_extraction.text import TfidfVectorizer
from keras.preprocessing.text import Tokenizer
from keras.preprocessing.sequence import pad_sequences
from keras.models import Sequential
from keras.layers import Activation, Dense, Dropout, Embedding, Flatten, Conv1D, MaxPooling1D, LSTM
#from keras import utils
from keras.callbacks import ReduceLROnPlateau, EarlyStopping
import nltk
from nltk.corpus import stopwords
from  nltk.stem import SnowballStemmer
import gensim
import re
from collections import Counter
import pickle
#import os
#import itertools

data_columns = ["target", "ids", "date", "flag", "user", "text"]

remove_words = "@\S+|https?:\S+|http?:\S|[^A-Za-z0-9]+"

SEQUENCE_LENGTH = 300
EPOCHS = 8

sentiment_thresholds=(0.4, 0.7)

#pandas
df = pd.read_csv("tweets.csv",encoding ='ISO-8859-1',names=data_columns)

decode_map={0: "NEGATIVE", 2: "NEUTRAL", 4: "POSITIVE"}
def decode_sentiment(label):
    return decode_map[int(label)]
df.target = df.target.apply(lambda x: decode_sentiment(x))

#nlp
stop_words = stopwords.words("english")
stemmer = SnowballStemmer("english")
def preprocess(text,stem=False):
    text = re.sub(remove_words, ' ', str(text).lower()).strip()
    tokens = []
    for token in text.split():
        if token not in stop_words:
            if stem:
                tokens.append(stemmer.stem(token))
            else:
                tokens.append(token)
    return " ".join(tokens)
df.text=df.text.apply(lambda x: preprocess(x))
df_train,df_test=tts(df,test_size=1-0.8,random_state=42)

#word2vec
documents=[x.split() for x in df_train.text]
w2v_model=gensim.models.word2vec.Word2Vec(size=300,\
                                            window=7,\
                                            min_count=10,workers=8)
w2v_model.build_vocab(documents)
words = w2v_model.wv.vocab.keys()
w2v_model.train(documents,total_examples=len(documents),epochs=32)

#tokenizing
tokenizer = Tokenizer()
tokenizer.fit_on_texts(df_train.text)
vocab_size=len(tokenizer.word_index)+1

x_train=pad_sequences(tokenizer.texts_to_sequences(df_train.text), maxlen=300)
x_test=pad_sequences(tokenizer.texts_to_sequences(df_test.text), maxlen=300)


labels = df_train.target.unique().tolist()
labels.append("Neutral")

#labelencoding
encoder = LabelEncoder()
encoder.fit(df_train.target.tolist())
y_train = encoder.transform(df_train.target.tolist())
y_test = encoder.transform(df_test.target.tolist())
y_train = y_train.reshape(-1,1)
y_test = y_test.reshape(-1,1)

W2V_SIZE=300

embedding_matrix=np.zeros((vocab_size, W2V_SIZE))
for word, i in tokenizer.word_index.items():
  if word in w2v_model.wv:
    embedding_matrix[i] = w2v_model.wv[word]


#keras model
embedding_layer=Embedding(vocab_size, W2V_SIZE, weights=[embedding_matrix],\
                            input_length=SEQUENCE_LENGTH, trainable=False)


model = Sequential()
model.add(embedding_layer)
model.add(Dropout(0.5))
model.add(LSTM(100, dropout=0.2, recurrent_dropout=0.2))
model.add(Dense(1, activation='sigmoid'))

model.compile(loss='binary_crossentropy',
              optimizer="adam",
              metrics=['accuracy'])

callbacks = [ ReduceLROnPlateau(monitor='val_loss', patience=5, cooldown=0),
              EarlyStopping(monitor='val_acc', min_delta=1e-4, patience=5)]

fitted=model.fit(x_train, y_train,
                    batch_size=BATCH_SIZE,
                    epochs=EPOCHS,
                    validation_split=0.1,
                    verbose=1,
                    callbacks=callbacks)

score = model.evaluate(x_test, y_test, batch_size=1024)

def decode_sentiment(score,neutral=True):
    if neutral:        
        label = "NEUTRAL"
        if score <= sentiment_thresholds[0]:
            label = "NEGATIVE"
        elif score >= sentiment_thresholds[1]:
            label = "POSITIVE"

        return label
    else:
        return "NEGATIVE" if score < 0.5 else "POSITIVE"


def predict(text, include_neutral=True):
    # Tokenize text
    x_test = pad_sequences(tokenizer.texts_to_sequences([text]),\
                           maxlen=SEQUENCE_LENGTH)
    # Predict
    score=model.predict([x_test])[0]
    # Decode sentiment
    label = decode_sentiment(score, include_neutral=include_neutral)

    return {"label": label, "score": float(score)}

#testing
y_pred= []
y_test_1d = list(df_test.target)
scores = model.predict(x_test, verbose=1, batch_size=8000)
y_pred_1d = [decode_sentiment(score,neutral=False) for score in scores]

#print(accuracy_score(y_test_1d, y_pred))
#print(classification_report(y_test_1d, y_pred))

model.save("model.h5")
w2v_model.save("model.w2v")
pickle.dump(tokenizer, open("tokenizer.pkl", "wb"), protocol=0)
pickle.dump(encoder, open("encoder.pkl", "wb"), protocol=0)
