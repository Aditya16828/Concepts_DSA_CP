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
print(number_of_subarrays(li))