def search(arr, target):
    n = len(arr)
    hi = n-1
    lo = 0
    while lo <= hi:
        mid = lo + ((hi - lo)//2)
        if arr[mid] == target:
            return mid
        if arr[mid] > arr[lo]:
            if target >= arr[lo] and target < arr[mid]:
                hi = mid-1
            else:
                lo = mid+1
        else:
            if target > arr[mid] and target <= arr[hi]:
                lo = mid+1
            else:
                hi = mid-1
    return -1

arr = [4, 5, 6, 7, 0, 1, 2]
print(search(arr, 2))