<<<<<<< HEAD
# cook your dish here
class Node:
	data = -1
	left = None
	right = None

	def __init__(self, data):
		self.data = data

def insert(root, data):
	if(root == None):
		return Node(data)
	if data < root.data:
		root.left = insert(root.left, data)
	else:
		root.right = insert(root.right, data)
	return root

def preorder_print(root):
	if(root == None):
		return
	print(root.data, end = ", ")
	preorder_print(root.left)
	preorder_print(root.right)

def inorder_print(root):
	if(root == None):
		return
	inorder_print(root.left)
	print(root.data, end = ", ")
	inorder_print(root.right)

def postorder_print(root):
	if(root == None):
		return
	postorder_print(root.left)
	postorder_print(root.right)
	print(root.data, end = ", ")

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

def display(li):
	for ele in li:
		print(ele.data, end = ", ")
	print()
	print("***********")

def max_depth_nodes(root):
	nodes = []
	q = []
	q.append(root)
	nodes.append(root)
	q.append(None)
	while len(q):
		cur = q.pop(0)
		if len(q) == 0:
		    break
		if cur == None:
		    q.append(None)
		    continue
		nodes.append(cur)
		if cur.left:
			q.append(cur.left)
		if cur.right:
			q.append(cur.right)
	return nodes

li = [int(x) for x in input().split()]
root = None
for ele in li:
	root = insert(root, ele)
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

print("****************")
mdn = max_depth_nodes(root)
for ele in mdn:
	print(ele.data, end = ", ")
=======
# cook your dish here
class Node:
	data = -1
	left = None
	right = None

	def __init__(self, data):
		self.data = data

def insert(root, data):
	if(root == None):
		return Node(data)
	if data < root.data:
		root.left = insert(root.left, data)
	else:
		root.right = insert(root.right, data)
	return root

def preorder_print(root):
	if(root == None):
		return
	print(root.data, end = ", ")
	preorder_print(root.left)
	preorder_print(root.right)

def inorder_print(root):
	if(root == None):
		return
	inorder_print(root.left)
	print(root.data, end = ", ")
	inorder_print(root.right)

def postorder_print(root):
	if(root == None):
		return
	postorder_print(root.left)
	postorder_print(root.right)
	print(root.data, end = ", ")

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

def display(li):
	for ele in li:
		print(ele.data, end = ", ")
	print()
	print("***********")

def max_depth_nodes(root):
	nodes = []
	q = []
	q.append(root)
	nodes.append(root)
	q.append(None)
	while len(q):
		cur = q.pop(0)
		if len(q) == 0:
		    break
		if cur == None:
		    q.append(None)
		    continue
		nodes.append(cur)
		if cur.left:
			q.append(cur.left)
		if cur.right:
			q.append(cur.right)
	return nodes

li = [int(x) for x in input().split()]
root = None
for ele in li:
	root = insert(root, ele)
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

print("****************")
mdn = max_depth_nodes(root)
for ele in mdn:
	print(ele.data, end = ", ")
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print()