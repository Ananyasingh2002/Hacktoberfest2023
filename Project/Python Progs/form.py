import tkinter as tk
from tkinter import messagebox

# Function to handle the form submission
def submit_form():
    name = name_entry.get()
    email = email_entry.get()
    messagebox.showinfo("Form Submitted", f"Name: {name}\nEmail: {email}")

# Create the main window
root = tk.Tk()
root.title("Simple Form")

# Create and place labels and entry fields
name_label = tk.Label(root, text="Name:")
name_label.pack()
name_entry = tk.Entry(root)
name_entry.pack()

email_label = tk.Label(root, text="Email:")
email_label.pack()
email_entry = tk.Entry(root)
email_entry.pack()

# Create and place the submit button
submit_button = tk.Button(root, text="Submit", command=submit_form)
submit_button.pack()

# Start the main event loop
root.mainloop()
