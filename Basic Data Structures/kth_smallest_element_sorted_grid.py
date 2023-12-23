<<<<<<< HEAD
from queue import PriorityQueue

def solve(grid, k):
    min_heap = PriorityQueue()
    tu = (grid[0][0], (0, 0))
    min_heap.put(tu)
    res = []
    while len(res) < k:
        tu = min_heap.get()
        res.append(tu[0])
        idx_tu = tu[1]
        tu_put = (grid[idx_tu[0]+1][idx_tu[1]], (idx_tu[0]+1, idx_tu[1]))
        min_heap.put(tu_put)
        tu_put = (grid[idx_tu[0]][idx_tu[1]+1], (idx_tu[0], idx_tu[1]+1))
        min_heap.put(tu_put)
    return res[k-1]

k = int(input())
n = int(input())
grid = []
for i in range(n):
    li = [int(x) for x in input().split()]
    grid.append(li)
print(solve(grid, k))
=======
from queue import PriorityQueue

def solve(grid, k):
    min_heap = PriorityQueue()
    tu = (grid[0][0], (0, 0))
    min_heap.put(tu)
    res = []
    while len(res) < k:
        tu = min_heap.get()
        res.append(tu[0])
        idx_tu = tu[1]
        tu_put = (grid[idx_tu[0]+1][idx_tu[1]], (idx_tu[0]+1, idx_tu[1]))
        min_heap.put(tu_put)
        tu_put = (grid[idx_tu[0]][idx_tu[1]+1], (idx_tu[0], idx_tu[1]+1))
        min_heap.put(tu_put)
    return res[k-1]

k = int(input())
n = int(input())
grid = []
for i in range(n):
    li = [int(x) for x in input().split()]
    grid.append(li)
print(solve(grid, k))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
