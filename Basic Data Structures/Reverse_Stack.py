def reverse(stack1):
    stack_temp = []
    while len(stack1):
        stack_temp.append(stack1.pop())
    return stack_temp

st = [1, 2, 3, 4, 5]
print(reverse(st))