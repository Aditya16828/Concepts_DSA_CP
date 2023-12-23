<<<<<<< HEAD
class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def insert_head(head, data):
	if(head == None):
		return Node(data)
	else:
		new_node = Node(data)
		new_node.next = head
		return new_node

def display(head):
	ptr = head
	while ptr:
		print(ptr.data, end="->")
		ptr = ptr.next
	print("x")

def reverse_node(head):
	curr, prev, curr_next = head, None, head.next
	while curr_next:
		curr.next = prev
		prev = curr
		curr = curr_next
		curr_next = curr_next.next
	curr.next = prev
	head = curr
	return head

def reverse_data_helper(left, right):
	if right == None:
		return left
	left = reverse_data_helper(left, right.next)
	if left:
		if left == right or right.next == left:
			left = None
		if left:
			left.data, right.data = right.data, left.data
			left = left.next
	return left

def reverse_data(head):
	reverse_data_helper(head, head)
	return head

head = None
li = [int(x) for x in input().split()]
"""li = []
for i in range(0, n):
	x = int(input())
	li.append(x)
"""
for ele in li:
	head = insert_head(head, ele)
display(head)
head = reverse_node(head)
=======
class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def insert_head(head, data):
	if(head == None):
		return Node(data)
	else:
		new_node = Node(data)
		new_node.next = head
		return new_node

def display(head):
	ptr = head
	while ptr:
		print(ptr.data, end="->")
		ptr = ptr.next
	print("x")

def reverse_node(head):
	curr, prev, curr_next = head, None, head.next
	while curr_next:
		curr.next = prev
		prev = curr
		curr = curr_next
		curr_next = curr_next.next
	curr.next = prev
	head = curr
	return head

def reverse_data_helper(left, right):
	if right == None:
		return left
	left = reverse_data_helper(left, right.next)
	if left:
		if left == right or right.next == left:
			left = None
		if left:
			left.data, right.data = right.data, left.data
			left = left.next
	return left

def reverse_data(head):
	reverse_data_helper(head, head)
	return head

head = None
li = [int(x) for x in input().split()]
"""li = []
for i in range(0, n):
	x = int(input())
	li.append(x)
"""
for ele in li:
	head = insert_head(head, ele)
display(head)
head = reverse_node(head)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
display(head)