import random
import time

class PetRock:
    def __init__(self, name):
        self.name = name
        self.happiness = 50
    #increases the happiness points by 10
    def pet(self):
        print(f"{self.name} purrs and wiggles a bit.")
        self.happiness += 10
   #after feeding increased the happiness points by 5
    def feed(self):
        print(f"{self.name} munches on an imaginary snack.")
        self.happiness += 5
   #scolding results in decrease of 10 points
    def scold(self):
        print(f"{self.name} gives you a disapproving look.")
        self.happiness -= 10
  #Simple if statement to check the current state of the pet
    def check_happiness(self):
        if self.happiness > 80:
            print(f"{self.name} is ecstatic!")
        elif self.happiness > 50:
            print(f"{self.name} is content.")
        elif self.happiness > 20:
            print(f"{self.name} is a bit grumpy.")
        else:
            print(f"{self.name} is really unhappy. You should do something!")

def main():
    #naming the pet
    name = input("Give a name to your virtual pet rock: ")
    pet_rock = PetRock(name)
    #introduction
    print(f"Welcome, {pet_rock.name} the virtual pet rock!")
   #while loops allows the user to interact until the user decides to quit by entering option 4
    while True:
        print("\nWhat do you want to do?")
        print("1. Pet")
        print("2. Feed")
        print("3. Scold")
        print("4. Quit")

        choice = input("Enter your choice by choosing the appropiate choice number: ")
  #set of if statements which invokes the appropiate function
        if choice == '1':
            pet_rock.pet()
        elif choice == '2':
            pet_rock.feed()
        elif choice == '3':
            pet_rock.scold()
        elif choice == '4':
            print(f"{pet_rock.name} says goodbye!")
            break
        else:
            print("Invalid choice. Please choose a valid option.")

        pet_rock.check_happiness()
        time.sleep(1)  # Pause for dramatic effect

if __name__ == "__main__":
    main()
