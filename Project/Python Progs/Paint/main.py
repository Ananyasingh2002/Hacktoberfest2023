import tkinter as tk
from tkinter.colorchooser import askcolor
from PIL import Image, ImageTk

class PaintApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Simple Paint App")
        self.root.geometry("800x600")
        
        self.color = "black"
        self.pen_size = 2
        self.prev_x, self.prev_y = None, None
        self.eraser_mode = False

        self.canvas = tk.Canvas(root, bg="white", bd=5, relief="ridge")
        self.canvas.pack(fill=tk.BOTH, expand=True)

        pencil_icon = Image.open("pencil.png")
        pencil_icon = pencil_icon.resize((32, 32), Image.ANTIALIAS)
        self.pencil_icon = ImageTk.PhotoImage(pencil_icon)
        self.pencil_button = tk.Button(root, image=self.pencil_icon, command=self.activate_pencil)
        self.pencil_button.pack(side=tk.LEFT, padx=10)

        eraser_icon = Image.open("eraser.png")
        eraser_icon = eraser_icon.resize((32, 32), Image.ANTIALIAS)
        self.eraser_icon = ImageTk.PhotoImage(eraser_icon)
        self.eraser_button = tk.Button(root, image=self.eraser_icon, command=self.activate_eraser)
        self.eraser_button.pack(side=tk.LEFT, padx=10)

        color_palette_icon = Image.open("color_palette.png")
        color_palette_icon = color_palette_icon.resize((32, 32), Image.ANTIALIAS)
        self.color_palette_icon = ImageTk.PhotoImage(color_palette_icon)
        self.color_button = tk.Button(root, image=self.color_palette_icon, command=self.choose_color)
        self.color_button.pack(side=tk.LEFT, padx=10)

        self.size_label = tk.Label(root, text="Pen Size:")
        self.size_label.pack(side=tk.LEFT)
        self.size_slider = tk.Scale(root, from_=1, to=20, orient=tk.HORIZONTAL, command=self.update_size)
        self.size_slider.set(self.pen_size)
        self.size_slider.pack(side=tk.LEFT)

        self.canvas.bind("<B1-Motion>", self.paint)
        self.canvas.bind("<ButtonRelease-1>", self.reset)

    def choose_color(self):
        color = askcolor()[1]
        if color:
            self.color = color

    def update_size(self, val):
        self.pen_size = int(val)

    def activate_pencil(self):
        self.eraser_mode = False

    def activate_eraser(self):
        self.eraser_mode = True

    def paint(self, event):
        x, y = event.x, event.y
        if self.prev_x and self.prev_y:
            if self.eraser_mode:
                self.canvas.create_oval(x - self.pen_size, y - self.pen_size, x + self.pen_size, y + self.pen_size, fill="white", width=0)
            else:
                self.canvas.create_line(self.prev_x, self.prev_y, x, y, fill=self.color, width=self.pen_size)
        self.prev_x, self.prev_y = x, y

    def reset(self, event):
        self.prev_x, self.prev_y = None, None

if __name__ == "__main__":
    root = tk.Tk()
    app = PaintApp(root)
    root.mainloop()
