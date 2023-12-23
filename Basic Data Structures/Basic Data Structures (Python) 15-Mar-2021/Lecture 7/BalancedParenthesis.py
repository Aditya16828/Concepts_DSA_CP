<<<<<<< HEAD
def isBalanced(str):
	mapping = {")": "(", "]": "[", "}": "{"}
	stack = []
	for ch in str:
		if ch in mapping:
			# means we have a closing char
			if len(stack) == 0:
				return False
			top = stack.pop() 
			if mapping[ch] != top:
				return False
		else:
			# means we have an opening char
			stack.append(ch)

	return len(stack) == 0

s = input()
print(isBalanced(s))
=======
def isBalanced(str):
	mapping = {")": "(", "]": "[", "}": "{"}
	stack = []
	for ch in str:
		if ch in mapping:
			# means we have a closing char
			if len(stack) == 0:
				return False
			top = stack.pop() 
			if mapping[ch] != top:
				return False
		else:
			# means we have an opening char
			stack.append(ch)

	return len(stack) == 0

s = input()
print(isBalanced(s))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
