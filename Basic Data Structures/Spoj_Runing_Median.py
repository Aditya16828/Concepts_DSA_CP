# https://www.spoj.com/problems/RMID2/
from queue import PriorityQueue

class Max_heap_ele:
	def __init__(self, x):
		self.x = x
	def __lt__(self, obj):
		return self.x > obj.x
	def __str__(self):
		return str(self.x)

def solve():
	n = int(input())
	min_rt_heap = PriorityQueue()
	max_lt_heap = PriorityQueue()
	# size of min_heap must be always greater than max_heap as -> "Take the smaller element as the median in case of even number of elements."
	median = n
	while n != 0:
	   if n == -1:
	       if min_rt_heap._qsize() == max_lt_heap._qsize():
	           median = max_lt_heap.get()
	           print(median)
	       else:
	           median = min_rt_heap.get()
	           print(median)
	   elif n > median:
	       min_rt_heap.put(n)
	   else:
	       max_lt_heap.put(Max_heap_ele(n))
	   
	   if min_rt_heap._qsize() - 1 == max_lt_heap._qsize(): # odd number of elements; median = lt_heap.top
	       median = max_lt_heap.get()
	       max_lt_heap.put(median)
	   elif min_rt_heap._qsize() == max_lt_heap._qsize():
	       median = max_lt_heap.get()
	       max_lt_heap.put(median)
	   else:
	       if max_lt_heap._qsize() > min_rt_heap._qsize():
	           min_rt_heap.put(max_lt_heap.get())
	       elif max_lt_heap._qsize() < min_rt_heap._qsize():
	           max_lt_heap.put(Max_heap_ele(min_rt_heap.get()))
	   
	   n = int(input())
	           

t = int(input())
for _ in range(t):
    solve()
    t -= 1