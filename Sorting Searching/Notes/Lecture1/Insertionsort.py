<<<<<<< HEAD
def insertion_sort(arr) -> None:
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1 
        arr[j+1] = key 



arr = [5,2,6,7,2,1,0,3]
insertion_sort(arr)
=======
def insertion_sort(arr) -> None:
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1 
        arr[j+1] = key 



arr = [5,2,6,7,2,1,0,3]
insertion_sort(arr)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(arr)