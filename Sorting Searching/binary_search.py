def binary_search(arr, target):
	n = len(arr)
	lo, hi = 0, n-1
	while lo <= hi:
		mid = lo + (hi-lo)//2
		if arr[mid] == target:
			return mid
		elif arr[mid] < target:
			lo = mid + 1
		else:
			hi = mid - 1
	return -1

li = [int(x) for x in input().split()]
key = int(input())
bs = binary_search(li, key)
if bs != -1:
	print("Found at ", bs)
else:
	print("Not found")
