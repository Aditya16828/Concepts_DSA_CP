<<<<<<< HEAD
class Queue:
    arr = []
    max_size = -1
    curr_size = -1
    front = -1
    rear = -1
    def __init__(self, n):
        self.arr = [0]*n
        self.front = 0
        self.max_size = n
        self.curr_size = 0
        self.rear = n-1
    
    def is_full(self):
        return self.curr_size == self.max_size
    
    def isEmpty(self):
        return self.curr_size == 0
    
    def push(self, data):
        if not self.is_full():
            self.rear = (self.rear+1)%self.max_size
            self.arr[self.rear] = data
            self.curr_size += 1
        else:
            print("Queue is Full")
    
    def pop(self):
        if not self.isEmpty():
            self.front = (self.front+1)%self.max_size
            self.curr_size -= 1
        else:
            print("Empty Queue")
    
    def get_front(self):
        if not self.isEmpty():
            return self.arr[self.front]
        else:
            print("Queue empty")

    def print_queue(self):
        t = 0
        i = self.front
        while t < self.curr_size:
            print(self.arr[i], end=" ")
            t += 1
            i = (i+1)%self.max_size
        print()

q = Queue(5)
q.push(10)
q.push(20)
q.push(30)
q.push(40)
q.print_queue()
q.push(100)
q.push(100)
q.push(100)
q.print_queue()
q.pop()
q.pop()
q.pop()
q.push(170)
=======
class Queue:
    arr = []
    max_size = -1
    curr_size = -1
    front = -1
    rear = -1
    def __init__(self, n):
        self.arr = [0]*n
        self.front = 0
        self.max_size = n
        self.curr_size = 0
        self.rear = n-1
    
    def is_full(self):
        return self.curr_size == self.max_size
    
    def isEmpty(self):
        return self.curr_size == 0
    
    def push(self, data):
        if not self.is_full():
            self.rear = (self.rear+1)%self.max_size
            self.arr[self.rear] = data
            self.curr_size += 1
        else:
            print("Queue is Full")
    
    def pop(self):
        if not self.isEmpty():
            self.front = (self.front+1)%self.max_size
            self.curr_size -= 1
        else:
            print("Empty Queue")
    
    def get_front(self):
        if not self.isEmpty():
            return self.arr[self.front]
        else:
            print("Queue empty")

    def print_queue(self):
        t = 0
        i = self.front
        while t < self.curr_size:
            print(self.arr[i], end=" ")
            t += 1
            i = (i+1)%self.max_size
        print()

q = Queue(5)
q.push(10)
q.push(20)
q.push(30)
q.push(40)
q.print_queue()
q.push(100)
q.push(100)
q.push(100)
q.print_queue()
q.pop()
q.pop()
q.pop()
q.push(170)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
q.print_queue()