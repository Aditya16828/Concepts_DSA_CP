<<<<<<< HEAD
"""
Q. Given an array, find the largest subarray with sum 0.
Solution:
	most optimised way to get subarray sum is prfix sum method.
	is there any subarray starting from ith index and ending at jth index,
	sum(i, j) = prefix[j] - prefix[i] + arr[i] = prefix[j] - prefix[i-1] = 0
	=> prefix[j] = prefix[i-1]
	Hence, p[k] = p[l] => sum(k+1, l) = 0
We can find all the pairs in the prefix sum array such that they both are equal.
Now, maintain a map which stores THE FIRST TIME WHEN x WAS ENCOUNTERED IN PREFIX SUM.
	<x, idx_x>
idx_x will store the first encounterd as we require the max length.
"""
def largest_subarray(li):
    n = len(li)
    map = {}
    prefix = 0
    l = 0
    for i in range(0, n):
        prefix += li[i]
        if map.keys().count(prefix) == 0:
            map[prefix] = i
        else:
            l = max(l, i - (map[prefix] + 1))
    return l

arr = [int(x) for x in input().split()]
print(largest_subarray(arr))
=======
"""
Q. Given an array, find the largest subarray with sum 0.
Solution:
	most optimised way to get subarray sum is prfix sum method.
	is there any subarray starting from ith index and ending at jth index,
	sum(i, j) = prefix[j] - prefix[i] + arr[i] = prefix[j] - prefix[i-1] = 0
	=> prefix[j] = prefix[i-1]
	Hence, p[k] = p[l] => sum(k+1, l) = 0
We can find all the pairs in the prefix sum array such that they both are equal.
Now, maintain a map which stores THE FIRST TIME WHEN x WAS ENCOUNTERED IN PREFIX SUM.
	<x, idx_x>
idx_x will store the first encounterd as we require the max length.
"""
def largest_subarray(li):
    n = len(li)
    map = {}
    prefix = 0
    l = 0
    for i in range(0, n):
        prefix += li[i]
        if map.keys().count(prefix) == 0:
            map[prefix] = i
        else:
            l = max(l, i - (map[prefix] + 1))
    return l

arr = [int(x) for x in input().split()]
print(largest_subarray(arr))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
            