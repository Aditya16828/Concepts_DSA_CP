def swap(a, b):
    temp = a
    a = b
    b = temp

def downheapify(heap, idx):
    rc = 2*idx + 2
    lc = 2*idx + 1
    if lc >= len(heap) and rc >= len(heap):
        return
    max_idx = idx
    if heap[lc] > heap[max_idx]:
        max_idx = lc
    if heap[rc] > heap[max_idx]:
        max_idx = rc
    if max_idx == idx:
        return
    temp = heap[idx]
    heap[idx] = heap[max_idx]
    heap[max_idx] = heap[idx]
    downheapify(heap, max_idx)

def downheapify_hs(heap, idx, heap_size):
    rc = 2*idx + 2
    lc = 2*idx + 1
    if lc >= heap_size and rc >= heap_size:
        return
    max_idx = idx
    if lc < heap_size and heap[lc] > heap[max_idx]:
        max_idx = lc
    if rc < heap_size and heap[rc] > heap[max_idx]:
        max_idx = rc
    if max_idx == idx:
        return
    temp = heap[idx]
    heap[idx] = heap[max_idx]
    heap[max_idx] = temp
    downheapify_hs(heap, max_idx, heap_size)

def build_heap(heap):
    i = len(heap)-1
    i = i//2 + 1
    while i >= 0:
        downheapify(heap, i)
        i -= 1
    return

def heap_sort(li):
    n = len(li)
    build_heap(li)
    i = n-1
    while i >= 0:
        temp = li[0]
        li[0] = li[i]
        li[i] = temp
        n -= 1
        downheapify_hs(li, 0, n)
        i -= 1

li = [int(x) for x in input().split()]
heap_sort(li)
print(li)