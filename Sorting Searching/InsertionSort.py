def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        temp = arr[i]
        j = i-1
        placed = False
        while j >= 0 and (not placed):
            if temp < arr[j]:
                arr[j+1] = arr[j]
            else:
                arr[j+1]=temp
                placed = True
            j -= 1
        if not placed:
            arr[0] = temp

ar = [1, 2, 3, 4, 5]
insertion_sort(ar)
print(ar)