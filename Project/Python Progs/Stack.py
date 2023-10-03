class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        else:
            return None  # You can also raise an exception here if you prefer

    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        else:
            return None  # You can also raise an exception here if you prefer

    def is_empty(self):
        return len(self.items) == 0
