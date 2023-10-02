import random
import string

print("------------------------Welcome to the Random Password Generator: ------------------------")
print("What type of Password you want to generate:-")
print("\n1. Alphabetical Password")
print("2. Alpha Numeric Password")
print("3. Symbolic Password")
print("4. Alpha Symbolic Password")
print("5. Numeric Symbolic Password")
print("6. Ultra Strong Password")


def alpha_numeric(n):
    main = string.ascii_letters + string.digits
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


def alpha(n):
    main = string.ascii_letters
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


def numeric(n):
    main = string.digits+string.punctuation
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


def symbolic(n):
    main = string.punctuation
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


def alpha_symbolic(n):
    main = string.punctuation + string.ascii_letters
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


def ultra_strong(n):
    main = string.punctuation + string.ascii_letters + string.digits
    password = ""
    for i in range(n):
        password += (random.choice(main))
    print("\nRandom password with length", n, "is: ", password)


while (1):
    ch = int(input("\nEnter Choice: "))
    if ch == 1:
        n = int(input("Enter the Length of the Password: "))
        alpha(n)

    elif ch == 2:
        n = int(input("Enter the Length of the Password: "))
        alpha_numeric(n)

    elif ch == 3:
        n = int(input("Enter the Length of the Password: "))
        symbolic(n)

    elif ch == 4:
        n = int(input("Enter the Length of the Password: "))
        alpha_symbolic(n)

    elif ch == 5:
        n = int(input("Enter the Length of the Password: "))
        numeric(n)

    elif ch == 6:
        n = int(input("Enter the Length of the Password: "))
        ultra_strong(n)
    else:
        break
