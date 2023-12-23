<<<<<<< HEAD
from tkinter import N
from traceback import print_tb


class Queue:
    primary = []
    secondary = []
    curr_size = -1
    def __init__(self):
        self.curr_size = 0
    
    def push(self, data):
        self.primary.append(data)
        self.curr_size += 1
    def pop(self):
        i = self.curr_size - 1
        while i > 0:
            i -= 1
            self.secondary.append(self.primary[-1])
            self.primary.pop()
        
        self.primary.pop()

        while len(self.secondary):
            x = self.secondary[-1]
            self.primary.append(x)
            self.secondary.pop()
        self.curr_size -= 1
        
    def display(self):
=======
from tkinter import N
from traceback import print_tb


class Queue:
    primary = []
    secondary = []
    curr_size = -1
    def __init__(self):
        self.curr_size = 0
    
    def push(self, data):
        self.primary.append(data)
        self.curr_size += 1
    def pop(self):
        i = self.curr_size - 1
        while i > 0:
            i -= 1
            self.secondary.append(self.primary[-1])
            self.primary.pop()
        
        self.primary.pop()

        while len(self.secondary):
            x = self.secondary[-1]
            self.primary.append(x)
            self.secondary.pop()
        self.curr_size -= 1
        
    def display(self):
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
