"""
Q. Given a list of intergers and a number k,
find the maximum values for all subarrays of size k.
"""
from collections import deque

def print_max_in_all_subarr(li, k):
    n = len(li)
    qu = deque()
    for i in range(k):
        while qu and li[i] >= li[qu[-1]]:
            qu.pop()
        qu.append(i)
    
    for i in range(k, n):
        if qu:
            print(li[qu[0]])
        
        while qu and qu[0] <= i-k:
            qu.popleft()
        
        while qu and li[i] >= li[qu[-1]]:
            qu.pop()
        qu.append(i)
    
    print(li[qu[0]])

arr = [int(x) for x in input(). split()]
k = int(input())
print_max_in_all_subarr(arr, k)