<<<<<<< HEAD
def isBalanced(str):
    map = {")": "(", "]": "[", "}": "{"}
    stack = []
    for ch in str:
        if ch in map:
            if(len(stack) == 0): 
                return False
            top = stack.pop()
            if map[ch] != top:
                return False
        else:
            stack.append(ch)
    return (len(stack) == 0)

str = input()
=======
def isBalanced(str):
    map = {")": "(", "]": "[", "}": "{"}
    stack = []
    for ch in str:
        if ch in map:
            if(len(stack) == 0): 
                return False
            top = stack.pop()
            if map[ch] != top:
                return False
        else:
            stack.append(ch)
    return (len(stack) == 0)

str = input()
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(isBalanced(str))