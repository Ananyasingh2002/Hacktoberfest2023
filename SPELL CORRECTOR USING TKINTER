from tkinter import *
from textblob import TextBlob

# Function to clear both the text entry boxes


def clearAll():

	# whole content of text entry area is deleted
	word1_field.delete(0, END)
	word2_field.delete(0, END)

# Function to get a corrected word


def correction():

	# get a content from entry box
	input_word = word1_field.get()

	# create a TextBlob object
	blob_obj = TextBlob(input_word)

	# get a corrected word
	corrected_word = str(blob_obj.correct())

	# insert method inserting the
	# value in the text entry box.
	word2_field.insert(10, corrected_word)


# Driver code
if __name__ == "__main__":

	# Create a GUI window
	root = Tk()

	# Set the background colour of GUI window
	root.configure(background='light green')

	# Set the configuration of GUI window (WidthxHeight)
	root.geometry("400x150")

	# set the name of tkinter GUI window
	root.title("Spell Corrector")

	# Create Welcome to Spell Corrector Application: label
	headlabel = Label(root, text='Welcome to Spell Corrector Application',
					fg='black', bg="red")

	# Create a "Input Word": label
	label1 = Label(root, text="Input Word",
				fg='black', bg='dark green')

	# Create a "Corrected Word": label
	label2 = Label(root, text="Corrected Word",
				fg='black', bg='dark green')

	# grid method is used for placing
	# the widgets at respective positions
	# in table like structure .
	# padx keyword argument used to set padding along x-axis .
	headlabel.grid(row=0, column=1)
	label1.grid(row=1, column=0)
	label2.grid(row=3, column=0, padx=10)

	# Create a text entry box
	# for filling or typing the information.
	word1_field = Entry()
	word2_field = Entry()

	# padx keyword argument used to set padding along x-axis .
	# pady keyword argument used to set padding along y-axis .
	word1_field.grid(row=1, column=1, padx=10, pady=10)
	word2_field.grid(row=3, column=1, padx=10, pady=10)

	# Create a Correction Button and attached
	# with correction function
	button1 = Button(root, text="Correction", bg="red", fg="black",
					command=correction)

	button1.grid(row=2, column=1)

	# Create a Clear Button and attached
	# with clearAll function
	button2 = Button(root, text="Clear", bg="red",
					fg="black", command=clearAll)

	button2.grid(row=4, column=1)

	# Start the GUI
	root.mainloop()
