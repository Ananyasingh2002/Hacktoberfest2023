from tkinter import *
root = Tk()
root.geometry('350x400')
root.title("Calculator")

def click(Event):
    global calci
    text = Event.widget.cget("text")
    if text == "=":
        if calci.get().isdigit():
            value = (int(calci.get()))
        else:
            value = eval(calci.get())
        calci.set(value)
        ent.update()
    elif text == "C":
        calci.set("")
        ent.update()
    else:
        calci.set(calci.get()+text)
        ent.update()


calci = StringVar()
calci.set("")

ent = Entry(root, textvariable=calci, width=40, font=("Arial Bold", 40))
ent.pack(fill=X, padx=10, pady=10)

f = Frame(bg="pink")
b = Button(f, text="C", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)

b = Button(f, text="9", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="8", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="7", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)
f.pack()

f = Frame(bg="pink")
b = Button(f, text="+", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=12, pady=10)
b.bind("<Button-1>", click)

b = Button(f, text="6", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)

b.bind("<Button-1>", click)


b = Button(f, text="5", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="4", padx=10, font=("Arial Bold", 20))
b.pack(side=RIGHT, padx=10, pady=10)
b.bind("<Button-1>", click)
f.pack()


f = Frame(bg="pink")
b = Button(f, text="-", padx=12, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=13, pady=10)
b.bind("<Button-1>", click)

b = Button(f, text="3", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=9, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="2", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=11, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="1", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=11, pady=10)
b.bind("<Button-1>", click)
f.pack()

f = Frame(bg="pink")


b = Button(f, text="*", padx=13, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)

b = Button(f, text="/", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="%", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)


b = Button(f, text="=", padx=10, font=("Arial Bold", 20))
b.pack(side=LEFT, padx=10, pady=10)
b.bind("<Button-1>", click)
f.pack()


root.mainloop()
