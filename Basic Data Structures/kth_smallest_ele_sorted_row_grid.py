from queue import PriorityQueue

def solve(grid, k):
    res = []
    min_heap = PriorityQueue()
    row, col = len(grid), len(grid[0])
    for i in range(row):
        tu = (grid[i][0], (i, 0))
        min_heap.put(tu)
    while len(res) < k:
        tu = min_heap.get()
        res.append(tu[0])
        idx_tu = tu[1]
        tu = (grid[idx_tu[0]][idx_tu[1]+1], (idx_tu[0], idx_tu[1]+1))
        min_heap.put(tu)
    return res[k-1]

k = int(input())
n = int(input())
grid = []
for i in range(n):
    li = [int(x) for x in input().split()]
    grid.append(li)
print(solve(grid, k))
