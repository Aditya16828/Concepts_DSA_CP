"""
You are given arrival time and departure time of n guests in 2 different lists.
Find the min total hotel rooms required for inculcating all the guests(24 hr format).

Sol: We just need to keep a track that whether we have a departure
before arrival or not.
"""
def min_rooms(arr, dept):
	arr.sort()
	dept.sort()

	i, j = 0, 0
	if arr[0] > dept[0]:
		return -1
	rooms = 1
	min_rooms = 1
	while i < len(arr) and j < len(dept):
		if arr[i] <= dept[j]:
			rooms += 1
			i += 1
		else:
			rooms -= 1
			j += 1

		if min_rooms < rooms:
			min_rooms = rooms
	return min_rooms

li1 = [int(x) for x in input().split()]
li2 = [int(x) for x in input().split()]
print(min_rooms(li1, li2))