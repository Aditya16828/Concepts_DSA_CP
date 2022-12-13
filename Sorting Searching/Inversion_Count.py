inv_count = 0

def merge(arr, start, mid, end):
	global inv_count
	i = start
	j = mid+1
	temp = []
	while(i <= mid and j <= end):
		if arr[i] > arr[j]:
			temp.append(arr[j])
			inv_count += (mid - i + 1)
			j += 1
		else:
			temp.append(arr[i])
			i += 1

	while i <= mid:
		temp.append(arr[i])
		i += 1

	while j <= end:
		temp.append(arr[j])
		j += 1
	#print(temp)
	x = start
	while(x <= end):
		arr[x] = temp[x-start]
		x += 1

def merge_sort_helper(arr, start, end):
	if start < end:
		mid = (start + end)//2
		merge_sort_helper(arr, start, mid)
		merge_sort_helper(arr, mid+1, end)
		merge(arr, start, mid, end)

def merge_sort(arr):
	merge_sort_helper(arr, 0, len(arr)-1)

li = [int(x) for x in input().split()]
merge_sort(li)
print("Array: ", li)
print("Inversion Count: ", inv_count)