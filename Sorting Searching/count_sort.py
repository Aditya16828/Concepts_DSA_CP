def count_sort(arr):
	max_ele = int(max(arr))
	min_ele = int(min(arr))
	n = len(arr)

	rng = max_ele - min_ele + 1
	frq = [0]*rng
	output = [0]*(n+1)

	for i in range(0, n):
		frq[arr[i] - min_ele] += 1

	for i in range(1, rng):
		frq[i] = frq[i]+frq[i-1]

	for i in range(n-1, -1, -1):
		output[frq[arr[i] - min_ele]] = arr[i]
		frq[arr[i]-min_ele] -= 1

	for i in range(0, n):
		arr[i] = output[i+1]

li = [int(x) for x in input().split()]
count_sort(li)
print(li)