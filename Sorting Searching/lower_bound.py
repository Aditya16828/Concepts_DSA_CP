def lower_bound(arr, key): # first value greater than equal to target
	n = len(arr)
	lo, hi = 0, n-1
	ans = -1
	while lo <= hi:
		mid = lo + (hi-lo)//2
		if arr[mid] >= key:
			ans = mid
			hi = mid-1
		else:
			lo = mid + 1
	return ans

li = [int(x) for x in input().split()]
key = int(input())
lb = lower_bound(li, key)
if lb != -1:
	print(lb)
else:
	print("Not found")