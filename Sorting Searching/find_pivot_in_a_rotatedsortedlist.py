<<<<<<< HEAD
def find_pivot(arr):
    n = len(arr)
    lo, hi = 0, n
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if (arr[mid] > arr[mid - 1]) and (arr[mid] > arr[mid + 1]):
            return mid
        if arr[mid] > arr[lo]:
            lo = mid + 1
        elif arr[mid] <= arr[lo]:
            hi = mid - 1
    return ans


li = [int(x) for x in input().split()]
print(find_pivot(li))
# 9 12 36 89 147 1 3 6
# 3 6 0 1 2 3
=======
def find_pivot(arr):
    n = len(arr)
    lo, hi = 0, n
    ans = -1
    while lo <= hi:
        mid = lo + (hi - lo) // 2
        if (arr[mid] > arr[mid - 1]) and (arr[mid] > arr[mid + 1]):
            return mid
        if arr[mid] > arr[lo]:
            lo = mid + 1
        elif arr[mid] <= arr[lo]:
            hi = mid - 1
    return ans


li = [int(x) for x in input().split()]
print(find_pivot(li))
# 9 12 36 89 147 1 3 6
# 3 6 0 1 2 3
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
