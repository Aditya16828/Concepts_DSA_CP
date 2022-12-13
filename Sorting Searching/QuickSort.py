from random import randrange

def partition(arr, start, end):
	p_idx = randrange(start, end)
	pivot = arr[p_idx]
	arr[end], arr[p_idx] = arr[p_idx], arr[end]
	m = start
	for i in range(start, end):
		if arr[i] <= pivot:
			arr[i], arr[m] = arr[m], arr[i]
			m += 1

	arr[end], arr[m] = arr[m], arr[end]
	return m

def quick_sort(arr, start, end):
	if(start >= end):
		return
	pidx = partition(arr, start, end)
	quick_sort(arr, start, pidx-1)
	quick_sort(arr, pidx+1, end)
	return

def sort(arr):
	quick_sort(arr, 0, len(arr)-1)

li = [int(x) for x in input().split()]
sort(li)
print(li)