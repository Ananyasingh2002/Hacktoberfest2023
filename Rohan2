# PRIVATE METHOD :-

class Finance:
    def __init__(self):
        self._Finance__revenue = None
        self.__revenue = 10000  # --->> Private data   (__)
        self._number_of_sales = 114  # --->> Protected data (_)

    def display(self):  # --->> Method to access the private and protected data.
        print(f"Revenue is : {self.__revenue} and number of sales : {self._number_of_sales}")

    @property
    def number_of_sales(self):
        return self._number_of_sales

    @property
    def Finance__revenue(self):
        return self._Finance__revenue


f1 = Finance()
f1.display()
print(f1.__dict__)
print(f1.Finance__revenue)  # -->> Private
print(f1.number_of_sales)    # -->> Protected
