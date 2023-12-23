<<<<<<< HEAD
def bubble_sort(arr) -> None:
    n = len(arr)
    for i in range(0, n-1): 
        swapped = False # flag
        for j in range(0, n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True 
        
        if not swapped:
            return 


arr = [5,2,6,7,2,1,0,3]
bubble_sort(arr)
print(arr)


=======
def bubble_sort(arr) -> None:
    n = len(arr)
    for i in range(0, n-1): 
        swapped = False # flag
        for j in range(0, n - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True 
        
        if not swapped:
            return 


arr = [5,2,6,7,2,1,0,3]
bubble_sort(arr)
print(arr)


>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
# Try to implement bubblesort recursively -> try to remove both the loops