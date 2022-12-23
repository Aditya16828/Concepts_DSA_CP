from queue import PriorityQueue

class MaxHeapEle:
	def __init__(self, x):
		self.x = x

	def __lt__(self, obj):
		return self.x > obj.x

	def __str__(self):
		return str(self.x)

	def value(self):
		return self.x

def solve(arr, k):
	max_heap = PriorityQueue()
	ans = -1
	for i in range(len(arr)):
		if max_heap._qsize() < k:
			max_heap.put(MaxHeapEle(arr[i]))
			continue
		else:
			temp = max_heap.get()
			if arr[i] < temp.value():
				max_heap.put(MaxHeapEle(arr[i]))
			else:
				max_heap.put(temp)
	ans = max_heap.get()
	return ans

li = [int(x) for x in input().split()]
k = int(input())
print(solve(li, k))