<<<<<<< HEAD
def peak(arr):
    lo, hi = 0, len(arr) - 1
    while lo < hi:
        mid = lo + (hi - lo)//2
        if arr[mid] > arr[mid+1]:
            hi = mid
        else:
            lo = mid + 1
    return lo

a = [1,2,1,3,5,6,4]
=======
def peak(arr):
    lo, hi = 0, len(arr) - 1
    while lo < hi:
        mid = lo + (hi - lo)//2
        if arr[mid] > arr[mid+1]:
            hi = mid
        else:
            lo = mid + 1
    return lo

a = [1,2,1,3,5,6,4]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(peak(a))