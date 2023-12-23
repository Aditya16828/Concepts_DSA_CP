<<<<<<< HEAD
# MAX HEAP
def upheapify(heap, idx):
	if idx == 0:
		return
	pi = (idx - 1) // 2
	if heap[pi] < heap[idx]:
		heap[pi], heap[idx] = heap[idx], heap[pi]
		upheapify(heap, pi)
	else:
		return

def downheapify(heap, idx):
	lc = 2*idx + 1
	rc = 2*idx + 2
	if lc >= len(heap) and rc >= len(heap):
		return
	largest = idx
	if lc < len(heap) and heap[lc] > heap[largest]:
		largest = lc
	if rc < len(heap) and heap[rc] > heap[largest]:
		largest = rc
	if largest == idx:
		return
	heap[largest], heap[idx] = heap[idx], heap[largest]
	downheapify(heap, largest)

def insert(heap, key):
	heap.append(key)
	upheapify(heap, len(heap)-1)

def get(heap):
	return heap[0]

def removepeek(heap):
	i = len(heap)-1
	heap[0], heap[i] = heap[i], heap[0]
	heap.pop()
	downheapify(heap, 0)

def remove(heap, idx):
	if idx == 0:
		removepeek(heap)
	heap[idx] = 1000000
	upheapify(heap, idx)
	heap[0], heap[len(heap)-1] = heap[len(heap)-1], heap[0]
	heap.pop()
	downheapify(heap, 0)

def build_heap(heap):
	i = len(heap)-1
	# approx n/2 nodes k liye 0 ops chahiye for downhepifying the nodes, so directly stated from (n/2 + 1) idx.
	i = (i//2) + 1
	while i >= 0:
		downheapify(heap, i)
		i -= 1
	return
 
heap = []
n = int(input())
while n > 0:
	n -= 1
	x = int(input())
	insert(heap, x)

=======
# MAX HEAP
def upheapify(heap, idx):
	if idx == 0:
		return
	pi = (idx - 1) // 2
	if heap[pi] < heap[idx]:
		heap[pi], heap[idx] = heap[idx], heap[pi]
		upheapify(heap, pi)
	else:
		return

def downheapify(heap, idx):
	lc = 2*idx + 1
	rc = 2*idx + 2
	if lc >= len(heap) and rc >= len(heap):
		return
	largest = idx
	if lc < len(heap) and heap[lc] > heap[largest]:
		largest = lc
	if rc < len(heap) and heap[rc] > heap[largest]:
		largest = rc
	if largest == idx:
		return
	heap[largest], heap[idx] = heap[idx], heap[largest]
	downheapify(heap, largest)

def insert(heap, key):
	heap.append(key)
	upheapify(heap, len(heap)-1)

def get(heap):
	return heap[0]

def removepeek(heap):
	i = len(heap)-1
	heap[0], heap[i] = heap[i], heap[0]
	heap.pop()
	downheapify(heap, 0)

def remove(heap, idx):
	if idx == 0:
		removepeek(heap)
	heap[idx] = 1000000
	upheapify(heap, idx)
	heap[0], heap[len(heap)-1] = heap[len(heap)-1], heap[0]
	heap.pop()
	downheapify(heap, 0)

def build_heap(heap):
	i = len(heap)-1
	# approx n/2 nodes k liye 0 ops chahiye for downhepifying the nodes, so directly stated from (n/2 + 1) idx.
	i = (i//2) + 1
	while i >= 0:
		downheapify(heap, i)
		i -= 1
	return
 
heap = []
n = int(input())
while n > 0:
	n -= 1
	x = int(input())
	insert(heap, x)

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(heap)