from queue import PriorityQueue

class MaxHeapEle:
    def __init__(self, x):
        self.x = x
    def __lt__(self, o):
        return self.x > o.x
    def __str__(self):
        return str(self.x)

max_heap = PriorityQueue()
max_heap.put(MaxHeapEle(10))
max_heap.put(MaxHeapEle(40))
max_heap.put(MaxHeapEle(20))
max_heap.put(MaxHeapEle(30))
max_heap.put(MaxHeapEle(-10))

print(max_heap._qsize())

print(max_heap.get())
print(max_heap.get())
print(max_heap.get())
