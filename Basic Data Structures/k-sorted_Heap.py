from queue import PriorityQueue

def solve(arr, k):
    min_heap = PriorityQueue()
    res = []
    i = 0
    while i <= (k+1):
        min_heap.put(arr[i])
        i += 1
    while i < len(arr):
        res.append(min_heap.get())
        min_heap.put(arr[i])
        i += 1
    while min_heap._qsize():
        res.append(min_heap.get())
    return res

li = [int(x) for x in input().split()]
k = int(input())
print(solve(li, k))