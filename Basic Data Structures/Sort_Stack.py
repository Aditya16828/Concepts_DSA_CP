<<<<<<< HEAD
def insert_ele_sorted(stack, ele):
    if(len(stack) == 0 or ele < stack[-1]):
        stack.append(ele)
        return
    else:
        temp = stack.pop()
        insert_ele_sorted(stack, ele)
        stack.append(temp)

def sort_stack(stack):
    if(len(stack) > 0):
        temp = stack.pop()
        sort_stack(stack)
        insert_ele_sorted(stack, temp)

s = [7, 9, 5, 3, 2, 8, 1]
sort_stack(s)
while len(s):
=======
def insert_ele_sorted(stack, ele):
    if(len(stack) == 0 or ele < stack[-1]):
        stack.append(ele)
        return
    else:
        temp = stack.pop()
        insert_ele_sorted(stack, ele)
        stack.append(temp)

def sort_stack(stack):
    if(len(stack) > 0):
        temp = stack.pop()
        sort_stack(stack)
        insert_ele_sorted(stack, temp)

s = [7, 9, 5, 3, 2, 8, 1]
sort_stack(s)
while len(s):
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
    print(s.pop(), end=" ")