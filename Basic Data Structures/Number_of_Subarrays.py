<<<<<<< HEAD
def number_of_subarrays(arr):
    stack = []
    n = len(arr)
    res = 0
    for i in range(0, n):
        while len(stack) and (arr[stack[-1]] > arr[i]):
            stack.pop()
        stack.append(i)
        res += len(stack) # stack mein jo bhi element hai usse start hone wale sub-arrays result form karega
    return res

li = [int(x) for x in input().split()]
=======
def number_of_subarrays(arr):
    stack = []
    n = len(arr)
    res = 0
    for i in range(0, n):
        while len(stack) and (arr[stack[-1]] > arr[i]):
            stack.pop()
        stack.append(i)
        res += len(stack) # stack mein jo bhi element hai usse start hone wale sub-arrays result form karega
    return res

li = [int(x) for x in input().split()]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(number_of_subarrays(li))