<<<<<<< HEAD
def merge(arr, start, end, mid):
    res = []
    j = mid+1
    i = start
    while i <= mid and j <= end:
        if(arr[i] < arr[j]):
            res.append(arr[i])
            i += 1
        else:
            res.append(arr[j])
            j += 1
    while i <= mid:
        res.append(arr[i])
        i += 1
    while j <= end:
        res.append(arr[j])
        j += 1
    for x in range(start, end+1):
        arr[x] = res[x-start]

def inplace_merge(arr, start, end, mid):
    i=start
    j=mid+1
    if arr[mid] <= arr[j]:
        return
    while mid < end:
        if(arr[i]<=arr[j]):
            i += 1
            mid += 1
        else:
            temp = arr[j]
            k = j
            while k > i:
                arr[k] = arr[k-1]
                k -= 1
            arr[i] = temp
            j += 1
            i += 1
            mid += 1

def merge_sort(arr, start, end):
    if(start < end):
        mid = (start+end) // 2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid+1, end)
        inplace_merge(arr, start, end, mid)

a = [5, 4, 3, 2, 1]
merge_sort(a, 0, len(a)-1)
=======
def merge(arr, start, end, mid):
    res = []
    j = mid+1
    i = start
    while i <= mid and j <= end:
        if(arr[i] < arr[j]):
            res.append(arr[i])
            i += 1
        else:
            res.append(arr[j])
            j += 1
    while i <= mid:
        res.append(arr[i])
        i += 1
    while j <= end:
        res.append(arr[j])
        j += 1
    for x in range(start, end+1):
        arr[x] = res[x-start]

def inplace_merge(arr, start, end, mid):
    i=start
    j=mid+1
    if arr[mid] <= arr[j]:
        return
    while mid < end:
        if(arr[i]<=arr[j]):
            i += 1
            mid += 1
        else:
            temp = arr[j]
            k = j
            while k > i:
                arr[k] = arr[k-1]
                k -= 1
            arr[i] = temp
            j += 1
            i += 1
            mid += 1

def merge_sort(arr, start, end):
    if(start < end):
        mid = (start+end) // 2
        merge_sort(arr, start, mid)
        merge_sort(arr, mid+1, end)
        inplace_merge(arr, start, end, mid)

a = [5, 4, 3, 2, 1]
merge_sort(a, 0, len(a)-1)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(a)