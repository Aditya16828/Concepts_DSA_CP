def sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while(key < arr[j] and j >= 0):
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key

arr = [int(x) for x in input().split()]
sort(arr)
print(arr)