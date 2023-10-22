import tkinter as tk

class Calculator:
    def __init__(self, root):
        self.root = root
        self.root.title("Calculator")

        self.result_var = tk.StringVar()

        # Entry to display the calculation and result
        entry = tk.Entry(root, textvariable=self.result_var, font=('Helvetica', 20))
        entry.grid(row=0, column=0, columnspan=4)

        # Buttons
        button_texts = [
            '7', '8', '9', '/',
            '4', '5', '6', '*',
            '1', '2', '3', '-',
            'C', '0', '=', '+'
        ]

        row = 1
        col = 0
        for button_text in button_texts:
            if button_text == '=':
                tk.Button(root, text=button_text, command=self.calculate).grid(row=row, column=col)
            elif button_text == 'C':
                tk.Button(root, text=button_text, command=self.clear).grid(row=row, column=col)
            else:
                tk.Button(root, text=button_text, command=lambda text=button_text: self.add_to_display(text)).grid(row=row, column=col)

            col += 1
            if col > 3:
                col = 0
                row += 1

    def add_to_display(self, text):
        current_display = self.result_var.get()
        if text == 'C':
            self.result_var.set('')
        else:
            self.result_var.set(current_display + text)

    def calculate(self):
        try:
            expression = self.result_var.get()
            result = eval(expression)
            self.result_var.set(result)
        except Exception:
            self.result_var.set("Error")

    def clear(self):
        self.result_var.set('')


if __name__ == "__main__":
    root = tk.Tk()
    calculator = Calculator(root)
    root.mainloop()
