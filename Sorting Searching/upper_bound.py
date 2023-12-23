def upper_bound(arr, target): # first element greater than target
	n = len(arr)
	lo, hi = 0, n-1
	ans = -1
	while lo <= hi:
		mid = lo + (hi-lo)//2
		if arr[mid] > target:
			ans = mid
			hi = mid - 1
		else:
			lo = mid + 1
	return ans

li = [int(x) for x in input().split()]
key = int(input())
ub = upper_bound(li, key)
if ub != -1:
	print(ub)
else:
	print("Not found")