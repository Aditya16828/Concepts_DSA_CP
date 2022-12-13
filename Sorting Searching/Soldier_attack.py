"""
You have an array of integers. The ith element represents the range
of the ith soldier, i.e, a soldier can attack positions from
[i - arr[i], i + arr[i]]. find min soldiers, to attack the whole array.
"""
def min_soldiers(arr):
	n = len(arr)
	range_arr = []
	for i in range(0, n):
		if arr[i] > 0:
			range_arr.append((i - arr[i], i + arr[i]))
	range_arr.sort()
	i = 0
	maxright = 0
	curr = 0
	count = 0
	while maxright < len(arr):
		if i == len(arr):
			return -1
		if range_arr[i][0] > maxright:
			return -1

		curr = range_arr[i][1]
		while i+1 < len(range_arr) and range_arr[i+1][0] <= maxright:
			i += 1
			curr = max(curr, range_arr[i][1])

		if curr < maxright:
			return -1
		count += 1
		maxright = curr+1
		i += 1

return count