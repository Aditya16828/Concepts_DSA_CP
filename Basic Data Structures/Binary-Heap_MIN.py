# MIN HEAP
def upheapify(heap, node_idx):
    if node_idx == 0: # already parent.
        return
    pi = (node_idx-1)//2
    if heap[node_idx] < heap[pi]:
        heap[node_idx], heap[pi] = heap[pi], heap[node_idx]
        upheapify(heap, pi)
    else:
        return

def downheapify(heap, p_idx):
    lc_idx = 2*p_idx + 1
    rc_idx = 2*p_idx + 2

    mini = p_idx
    if lc_idx >= len(heap) and rc_idx >= len(heap): # leaf nodes
        return
    if heap[lc_idx] < heap[mini]:
        mini = lc_idx
    if heap[rc_idx] < heap[mini]:
        mini = rc_idx
    if mini == p_idx:
        return
    heap[p_idx], heap[mini] = heap[mini], heap[p_idx] # parent and minimum is swapped and hence mini stores value > minimum_value
    downheapify(heap, mini)

def get(heap):
    return heap[0]

def remove_root(heap):
    i = len(heap) - 1
    heap[0], heap[i] = heap[i], heap[0]
    heap.pop()
    downheapify(heap, 0)

def remove(heap, idx):
    if idx == 0:
        remove_root(heap)
    heap[idx] = -1000000 # replace the element to be deleted with -inf and then upheapify
    upheapify(heap, idx)
    # now remove the -inf root by swapping with rightmost leaf node and remove the node.
    heap[0], heap[len(heap)-1] = heap[len(heap)-1], heap[0]
    heap.pop()
    # then downheapify
    downheapify(heap, 0)

def insert(heap, data):
    heap.append(data)
    upheapify(heap, len(heap)-1)

heap = []
n = int(input())
while n > 0:
	n -= 1
	x = int(input())
	insert(heap, x)
print(heap)
remove_root(heap)
print(heap)
remove(heap, 3)
print(heap)