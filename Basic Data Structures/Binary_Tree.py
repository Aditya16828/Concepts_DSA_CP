<<<<<<< HEAD
def max(a, b):
	if(a > b):
		return a
	else:
		return b

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

def height(root):
	if root == None:
		return 0
	return 1 + max(height(root.left), height(root.right))

countNode = {}
def count_Nodes(root):
	if root == None:
		return 0
	global countNode
	c_left = count_Nodes(root.left)
	c_right = count_Nodes(root.right)
	countNode[root] = 1 + c_left + c_right
	return countNode[root]

tilt_node = {}
sum_tilt = 0
def tilt(root):
	if root == None:
		return 0
	global tilt_node, sum_tilt
	sum_left = tilt(root.left)
	sum_right = tilt(root.right)
	tilt_node[root] = abs(sum_left - sum_right);
	sum_tilt += tilt_node[root]
	return root.data + sum_left + sum_right

root = build_BT()
preorder_print(root)
print()
inorder_print(root)
print()
postorder_print(root)
print()
tilt(root)
print("Total Node: ", count_Nodes(root))
print("Count Node: ")
for ele in countNode.keys():
	print(ele.data, "-", countNode[ele])
print("Tilt Node: ")
for ele in tilt_node.keys():
	print(ele.data, "-", tilt_node[ele])
print("Sum of Tilt: ", sum_tilt)

"""
1
2
4
-1
-1
-1
3
5
-1
6
7
-1
-1
8
-1
-1
-1

=======
def max(a, b):
	if(a > b):
		return a
	else:
		return b

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

def height(root):
	if root == None:
		return 0
	return 1 + max(height(root.left), height(root.right))

countNode = {}
def count_Nodes(root):
	if root == None:
		return 0
	global countNode
	c_left = count_Nodes(root.left)
	c_right = count_Nodes(root.right)
	countNode[root] = 1 + c_left + c_right
	return countNode[root]

tilt_node = {}
sum_tilt = 0
def tilt(root):
	if root == None:
		return 0
	global tilt_node, sum_tilt
	sum_left = tilt(root.left)
	sum_right = tilt(root.right)
	tilt_node[root] = abs(sum_left - sum_right);
	sum_tilt += tilt_node[root]
	return root.data + sum_left + sum_right

root = build_BT()
preorder_print(root)
print()
inorder_print(root)
print()
postorder_print(root)
print()
tilt(root)
print("Total Node: ", count_Nodes(root))
print("Count Node: ")
for ele in countNode.keys():
	print(ele.data, "-", countNode[ele])
print("Tilt Node: ")
for ele in tilt_node.keys():
	print(ele.data, "-", tilt_node[ele])
print("Sum of Tilt: ", sum_tilt)

"""
1
2
4
-1
-1
-1
3
5
-1
6
7
-1
-1
8
-1
-1
-1

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
"""