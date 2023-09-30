d = {'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12,
     'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24,
     'z': 25}
key_list = list(d.keys())
val_list = list(d.values())


def getKey(txt, key):
    txt = txt.lower()
    key = key.lower()
    ans = list(key)
    i = 0
    while len(ans) != len(txt):
        if i == len(key):
            i = 0
        ans.append(key[i])
        i += 1
    return "".join(ans)


def encrypt(txt, key):
    txt = txt.lower()
    key = key.lower()
    k_list = []
    t_list = []
    for x in key:
        k_list.append(ord(x) - 97)

    for x in txt:
        t_list.append(ord(x) - 97)

    ans = []
    i = 0
    while i != len(key):
        z = k_list[i] + t_list[i]
        ans.append(z % 26)
        i += 1

    ans2 = []
    for j in ans:
        pos = val_list.index(j)
        ans2.append(key_list[pos])

    return "".join(ans2)


def decrypt(txt, key):
    txt = txt.lower()
    key = key.lower()

    t_list = []
    k_list = []
    for i in list(txt):
        t_list.append(d.get(i))

    for j in list(key):
        k_list.append(d.get(j))
    ans = []
    ans2 = []
    j = 0
    t_list = [int(i) for i in t_list]
    k_list = [int(i) for i in k_list]

    while j != len(k_list):
        z = t_list[j] - k_list[j]
        ans.append(z % 26)
        j += 1

    for i in ans:
        pos = val_list.index(i)
        ans2.append(key_list[pos])
    return "".join(ans2)


text = input("Enter text - ")
keyword = input("Enter key - ")
text = text.replace(" ","")
keyword = keyword.replace(" ","")
new_key = getKey(text, keyword)
e_text = encrypt(text, new_key)
print("Encrypted text - " + e_text)
d_text = decrypt(e_text, new_key)
print("Decrypted text - " + d_text)
