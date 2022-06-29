"""
Given an array, find any one element in the array that follows the property:
	a[i] > a[i+1]	(if i+1 exist)
		and
	a[i] < a[i-1]	(if i-1 exist)
"""
def peak_element(arr):
	n = len(arr)
	lo, hi = 0, n-1
	while lo <= hi:
		mid = lo + (hi-lo)//2
		if arr[mid] < arr[mid+1]:
			lo = mid+1
		else:
			hi = mid-1
	return lo

li = [1, 2, 1, 3, 5, 6, 4]
print(peak_element(li))