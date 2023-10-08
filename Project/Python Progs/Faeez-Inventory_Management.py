import tkinter as tk
from tkinter import messagebox
from tkinter import ttk

class InventoryItem:
    def __init__(self, name, price, quantity):
        self.name = name
        self.price = price
        self.quantity = quantity

class Inventory:
    def __init__(self):
        self.items = []

    def add_item(self, item):
        self.items.append(item)

    def remove_item(self, item_name):
        for item in self.items:
            if item.name == item_name:
                self.items.remove(item)
                return True
        return False

    def update_item(self, item_name, new_price, new_quantity):
        for item in self.items:
            if item.name == item_name:
                item.price = new_price
                item.quantity = new_quantity
                return True
        return False

    def display_inventory(self):
        return "\n".join([f"{item.name} - Price: ${item.price:.2f} - Quantity: {item.quantity}" for item in self.items])

def add_item():
    name = name_entry.get()
    price = float(price_entry.get())
    quantity = int(quantity_entry.get())
    item = InventoryItem(name, price, quantity)
    inventory.add_item(item)
    update_display()
    messagebox.showinfo("Success", f"{name} added to Muhammad Faeez's inventory.")

def remove_item():
    item_name = name_entry.get()
    if inventory.remove_item(item_name):
        update_display()
        messagebox.showinfo("Success", f"{item_name} removed from Muhammad Faeez's inventory.")
    else:
        messagebox.showerror("Error", f"{item_name} not found in Muhammad Faeez's inventory.")

def update_item():
    item_name = name_entry.get()
    new_price = float(price_entry.get())
    new_quantity = int(quantity_entry.get())
    if inventory.update_item(item_name, new_price, new_quantity):
        update_display()
        messagebox.showinfo("Success", f"{item_name} updated in Muhammad Faeez's inventory.")
    else:
        messagebox.showerror("Error", f"{item_name} not found in Muhammad Faeez's inventory.")

def update_display():
    inventory_text.set(inventory.display_inventory())

inventory = Inventory()

root = tk.Tk()
root.title("Muhammad Faeez's Inventory Management")

# Styling
style = ttk.Style()
style.configure("TButton", padding=(10, 5), font=('Helvetica', 12))

frame = ttk.Frame(root, padding=10)
frame.grid(row=0, column=0, padx=20, pady=20)

name_label = ttk.Label(frame, text="Item Name:")
name_label.grid(row=0, column=0, sticky="w")

name_entry = ttk.Entry(frame)
name_entry.grid(row=0, column=1, padx=10, pady=5)

price_label = ttk.Label(frame, text="Item Price:")
price_label.grid(row=1, column=0, sticky="w")

price_entry = ttk.Entry(frame)
price_entry.grid(row=1, column=1, padx=10, pady=5)

quantity_label = ttk.Label(frame, text="Item Quantity:")
quantity_label.grid(row=2, column=0, sticky="w")

quantity_entry = ttk.Entry(frame)
quantity_entry.grid(row=2, column=1, padx=10, pady=5)

add_button = ttk.Button(frame, text="Add Item", command=add_item)
add_button.grid(row=3, column=0, columnspan=2, pady=10)

remove_button = ttk.Button(frame, text="Remove Item", command=remove_item)
remove_button.grid(row=4, column=0, columnspan=2, pady=10)

update_button = ttk.Button(frame, text="Update Item", command=update_item)
update_button.grid(row=5, column=0, columnspan=2, pady=10)

inventory_text = tk.StringVar()
inventory_label = ttk.Label(frame, textvariable=inventory_text, font=('Helvetica', 14))
inventory_label.grid(row=6, column=0, columnspan=2, pady=20)

update_display()

root.mainloop()
