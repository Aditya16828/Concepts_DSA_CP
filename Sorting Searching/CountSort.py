def sort(arr):
	max_ele = max(arr)
	min_ele = min(arr)
	bucket = [0]*(max_ele - min_ele + 1)
	n = len(arr)
	for i in range(0, n):
		bucket[arr[i]-min_ele] += 1
	
	# prefix calculation
	for i in range(1, max_ele-min_ele+1):
		bucket[i] += bucket[i-1]

	ans = [0]*n
	for i in range(0, n):
		ans[bucket[arr[i]-min_ele]-1] = arr[i]
		bucket[arr[i]-min_ele] -= 1

	return ans

li = [int(x) for x in input().split()]
ans = sort(li)
print(ans)