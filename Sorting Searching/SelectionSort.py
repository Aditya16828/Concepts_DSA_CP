def find_min_index(arr, start, end) -> int:
    min_index = start
    min_ele = arr[min_index]
    i =start+1
    while i < end:
        if(min_ele > arr[i]):
            min_ele = arr[i]
            min_index = i
        i += 1
    return min_index

def selection_sort(arr):
    n = len(arr)
    for i in range(0, n-1):
        idx = find_min_index(arr, i+1, n)
        if arr[idx] < arr[i]:
            arr[idx], arr[i] = arr[i], arr[idx]

ar = [7, 6, 5, 4, 3, 2, 1]
selection_sort(ar)
print(ar)