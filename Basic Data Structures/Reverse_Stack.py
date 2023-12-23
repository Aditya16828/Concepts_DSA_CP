<<<<<<< HEAD
def reverse(stack1):
    stack_temp = []
    while len(stack1):
        stack_temp.append(stack1.pop())
    return stack_temp

st = [1, 2, 3, 4, 5]
=======
def reverse(stack1):
    stack_temp = []
    while len(stack1):
        stack_temp.append(stack1.pop())
    return stack_temp

st = [1, 2, 3, 4, 5]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(reverse(st))