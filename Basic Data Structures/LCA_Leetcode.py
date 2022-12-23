# https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Node:
	data = -1
	left = None
	right = None

	def __init__(self, data):
		self.data = data

def build_BT():
	data = int(input())
	if data == -1:
		return None
	root = Node(data)
	root.left = build_BT()
	root.right = build_BT()
	return root

def preorder_print(root):
	if(root == None):
		return
	print(root.data, end = ", ")
	preorder_print(root.left)
	preorder_print(root.right)

def inorder_print(root):
	if root == None:
		return
	inorder_print(root.left)
	print(root.data, end = ", ")
	inorder_print(root.right)

def postorder_print(root):
	if root == None:
		return
	postorder_print(root.left)
	postorder_print(root.right)
	print(root.data, end=", ")

def levelorder_levelwise(root):
	q = []
	q.append(root)
	q.append(None)
	while q:
		curr = q.pop(0)
		if not q:
			break
		if curr == None:
			print()
			q.append(None)
			continue
		print(curr.data, end = ", ")
		if curr.left:
			q.append(curr.left)
		if curr.right:
			q.append(curr.right)

ispresent_a = False
ispresent_b = False

def LCA_helper(root, a, b):
	if root == None:
		return None

	global ispresent_a, ispresent_b

	lst = LCA_helper(root.left, a, b)
	rst = LCA_helper(root.right, a, b)

	if root == a:
		ispresent_a = True

	if root == b:
		ispresent_b = True

	if lst and rst:
		return root

	if ispresent_a and ispresent_b and lst:
		return lst

	if ispresent_a and ispresent_b and rst:
		return rst

	if ispresent_a:
		return a

	if ispresent_b:
		return b

	return (lst or rst)

def LCA(root, a, b):
	global ispresent_a, ispresent_b
	if ispresent_a and ispresent_b and LCA_helper(root, a, b):
		return LCA_helper(root, a, b).data
	else:
		return -1

root = build_BT()
print("Pre-order: ")
preorder_print(root)
print()

print("In-order: ")
inorder_print(root)
print()

print("Post-order: ")
postorder_print(root)
print()

print("levelorder levelwise: ")
levelorder_levelwise(root)
print()