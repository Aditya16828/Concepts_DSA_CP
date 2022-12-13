# Given a list of Integers, find the next greater element for each of the elements in the list
# Variations: Next Smaller, Just larger/ previous larger(run the whole algo from end)
# example: 10 7 4 2 9 10 11 3 2
def next_greater(arr):
    n = len(arr)
    stack = []
    res = [-1]*n
    for i in range(0, n):
        while (len(stack) > 0) and (arr[stack[-1]] < arr[i]):
            temp = stack.pop()
            res[temp] = arr[i]
        stack.append(i)
    return res

def next_smaller(arr):
    n = len(arr)
    stack = []
    res = [-1]*n
    for i in range(0, n):
        while len(stack) > 0 and (arr[stack[-1]] > arr[i]):
            temp = stack.pop()
            res[temp] = arr[i]
        stack.append(i)
    return res

li = [int(x) for x in input().split()]
print(next_smaller(li))