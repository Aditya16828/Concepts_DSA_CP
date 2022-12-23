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
print(isBalanced(str))