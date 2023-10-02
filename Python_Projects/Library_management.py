import time
book_name = []
author_name = []
timee = []
rating = []
Genre = []
book = []
name = []
days = []
tome = []
iss = 0
count = 0


def add():
    global count
    a = input("Enter Genre: ")
    b = input("Enter Book name: ")
    c = input("Enter Author name: ")
    d = input("Enter the rating: ")
    Genre.append(a)
    book_name.append(b)
    author_name.append(c)
    rating.append(d)
    timee.append(time.ctime())
    print("Record Entered Successfully\n")
    count += 1


def Remove():
    global count
    stock()
    i = int(input("Enter the record you want to remove"))
    del Genre[i-1]
    del timee[i-1]
    del book_name[i-1]
    del author_name[i-1]
    del rating[i-1]
    count -= 1
    print("Record deleted Successfully\n")


def Issue():
    global count
    global iss
    stock()
    k = (input("Enter which book you want to take: "))
    try:
        d = book_name.index(k)
        a = input("Enter First name: ")
        b = input("Enter Last name: ")
        c = input("Enter number of days: ")
        name.append(a+" "+b)
        days.append(c)
        book.append(book_name[d])
        tome.append(time.ctime())
        del Genre[d]
        del timee[d]
        del book_name[d]
        del author_name[d]
        del rating[d]
        iss += 1
        count -= 1
        print("Book Issued Successfully....\n")

    except ValueError:
        print("Book not found....try again")


def Return():
    a = input("Enter your name:  ")
    try:
        c = name.index(a)
        b = int(input("Enter how many days has it been till you take the book: "))
        m = int(days[c])-b
        if m < 0:
            print("Fine of ", abs(5*m), " Rs is applicable on you.")
            while (1):
                d = (input("Do you wish to pay fine Y/N: "))
                if d == "N":
                    print("Please pay the fine")
                else:
                    print("Book Returned Successfully")
                    break
        else:
            add()
            print("Book Returned Successfully")

    except ValueError:
        print(a, "does not exist\n")


def details():
    print("--------------------------Details of Issuer--------------------------")
    print("{:^67}".format(time.ctime()))
    global iss
    u = 0
    s = "Name{:<12}Book Name{:<10}Days{:<7}Time"
    print(s.format("", "", ""))
    while u < iss:
        print("{:<14}".format(name[u]), "{:<17}".format(book[u]), "{:<10}".format(
            days[u]), tome[u])
        u += 1
    print("\n")


def stock():
    print("--------------------------Books Availiable--------------------------")
    print("{:^67}".format(time.ctime()))
    global count
    u = 0
    s = "Boook Name{:<11}Author Name{:<10}Genre{:<7}Rating{:<7}Time"
    print(s.format("", "", "", "", ""))
    while u < count:
        print("{:<20}".format(book_name[u]), "{:<20}".format(author_name[u]), "{:<11}".format(
            Genre[u]), "{:<12}".format(rating[u]), timee[u])
        u += 1
    print("\n")


print("----------------Welcome to the Library Management System----------------")
print("What operation you want to perform : \n")
print("1. Add Book Record ")
print("2. Remove Book Record")
print("3. Issue a Book")
print("4. Return a Book")
print("5. Display the stock")
print("6. Display the issuer details")
print("7. Exit\n")

while (1):
    ch = int(input("Enter choice: "))
    if ch == 1:
        add()
    elif ch == 2:
        Remove()
    elif ch == 3:
        Issue()
    elif ch == 4:
        Return()
    elif ch == 5:
        stock()
    elif ch == 6:
        details()
    else:
        print("Please come Again....:)")
        break
