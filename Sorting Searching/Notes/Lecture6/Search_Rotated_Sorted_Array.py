<<<<<<< HEAD
def search(arr, t):
    # TC O(logn)
    n = len(arr)
    lo, hi = 0, n-1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if arr[mid] == t:
            return mid 
        elif arr[mid] >= arr[lo]:
            # case1
            if t >= arr[lo] and t < arr[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:
            # case2
            if t <= arr[hi] and t > arr[mid]:
                lo = mid + 1
            else:
                hi = mid - 1
            
    return -1

arr = [4,5,6,7,0,1,2]
=======
def search(arr, t):
    # TC O(logn)
    n = len(arr)
    lo, hi = 0, n-1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if arr[mid] == t:
            return mid 
        elif arr[mid] >= arr[lo]:
            # case1
            if t >= arr[lo] and t < arr[mid]:
                hi = mid - 1
            else:
                lo = mid + 1
        else:
            # case2
            if t <= arr[hi] and t > arr[mid]:
                lo = mid + 1
            else:
                hi = mid - 1
            
    return -1

arr = [4,5,6,7,0,1,2]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(search(arr, 3))