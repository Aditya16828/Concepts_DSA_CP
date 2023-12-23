from math import ceil


def merge(arr1, arr2):
    n1 = len(arr1)
    n2 = len(arr2)

    gap = int(ceil(n1+n2)/2)

    arr = []
    for i in arr1:
        arr.append(i)
    for i in arr2:
        arr.append(i)

    while(gap):
        p1 = 0
        p2 = int(p1+gap)
        
        while p2 < len(arr):
            if arr[p1] > arr[p2]:
                arr[p1], arr[p2] = arr[p2], arr[p1]
            
            p1 += 1
            p2 += 1
        
        if gap > 1 and gap % 2 == 1:
            gap = gap//2 + 1
        else:
            gap = gap//2
    
    return arr


arr1 = [int(i) for i in input().split()]
arr2 = [int(i) for i in input().split()]
arr = merge(arr1, arr2)
print(arr)