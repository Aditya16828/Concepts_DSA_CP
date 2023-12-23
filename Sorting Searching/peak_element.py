<<<<<<< HEAD
"""
Given an array, find any one element in the array that follows the property:
	a[i] > a[i+1]	(if i+1 exist)
		and
	a[i] < a[i-1]	(if i-1 exist)
"""
def peak(arr):
    n = len(arr)
    lo, hi = 0, n-1
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if (mid+1 < n and mid-1 >= 0) and (arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]):
            return mid
        elif arr[mid] < arr[mid+1]:
            lo = mid+1
        else:
            hi = mid-1
    return lo

li = [int(x) for x in input().split()]
=======
"""
Given an array, find any one element in the array that follows the property:
	a[i] > a[i+1]	(if i+1 exist)
		and
	a[i] < a[i-1]	(if i-1 exist)
"""
def peak(arr):
    n = len(arr)
    lo, hi = 0, n-1
    while lo <= hi:
        mid = lo + (hi - lo)//2
        if (mid+1 < n and mid-1 >= 0) and (arr[mid] > arr[mid+1] and arr[mid] > arr[mid-1]):
            return mid
        elif arr[mid] < arr[mid+1]:
            lo = mid+1
        else:
            hi = mid-1
    return lo

li = [int(x) for x in input().split()]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(peak(li))