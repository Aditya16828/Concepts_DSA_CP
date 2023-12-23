<<<<<<< HEAD
def count_sort(arr, tens):
	n = len(arr)

	rng = 10
	frq = [0]*rng
	output = [0]*(n+1)

	for i in range(0, n):
		frq[(arr[i]//tens)%10] += 1

	for i in range(1, rng):
		frq[i] = frq[i]+frq[i-1]

	for i in range(n-1, -1, -1):
		output[frq[(arr[i]//tens)%10]] = arr[i]
		frq[(arr[i]//tens)%10] -= 1

	for i in range(0, n):
		arr[i] = output[i+1]

def radix_sort(arr):
	exp = 1
	max_ele = int(max(arr))
	while exp <= max_ele:
		count_sort(arr, exp)
		exp *= 10

li = [int(x) for x in input().split()]
radix_sort(li)
=======
def count_sort(arr, tens):
	n = len(arr)

	rng = 10
	frq = [0]*rng
	output = [0]*(n+1)

	for i in range(0, n):
		frq[(arr[i]//tens)%10] += 1

	for i in range(1, rng):
		frq[i] = frq[i]+frq[i-1]

	for i in range(n-1, -1, -1):
		output[frq[(arr[i]//tens)%10]] = arr[i]
		frq[(arr[i]//tens)%10] -= 1

	for i in range(0, n):
		arr[i] = output[i+1]

def radix_sort(arr):
	exp = 1
	max_ele = int(max(arr))
	while exp <= max_ele:
		count_sort(arr, exp)
		exp *= 10

li = [int(x) for x in input().split()]
radix_sort(li)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(li)