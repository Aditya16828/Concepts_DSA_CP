<<<<<<< HEAD
def count_sort(arr) -> None:
    # O(n + k)
    max_element = int(max(arr))
    min_element = int(min(arr))
    k = max_element - min_element + 1
    n = len(arr)

    freq = [0]*(k)
    output = [0]*(n+1)

    # fill the frequency array
    for i in range(n):
        freq[arr[i] - min_element] += 1
    

    # prefix array
    for i in range(1, k):
        freq[i] = freq[i] + freq[i-1]
    
    for i in range(n-1, -1, -1):
        output[freq[arr[i]-min_element]] = arr[i]
        freq[arr[i] - min_element] -= 1
    
    for i in range(0, n):
        arr[i] = output[i+1]
    
    return 

arr = [10,7,1,8,-1,9, 9,1,5, 10]
count_sort(arr)
=======
def count_sort(arr) -> None:
    # O(n + k)
    max_element = int(max(arr))
    min_element = int(min(arr))
    k = max_element - min_element + 1
    n = len(arr)

    freq = [0]*(k)
    output = [0]*(n+1)

    # fill the frequency array
    for i in range(n):
        freq[arr[i] - min_element] += 1
    

    # prefix array
    for i in range(1, k):
        freq[i] = freq[i] + freq[i-1]
    
    for i in range(n-1, -1, -1):
        output[freq[arr[i]-min_element]] = arr[i]
        freq[arr[i] - min_element] -= 1
    
    for i in range(0, n):
        arr[i] = output[i+1]
    
    return 

arr = [10,7,1,8,-1,9, 9,1,5, 10]
count_sort(arr)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(arr)