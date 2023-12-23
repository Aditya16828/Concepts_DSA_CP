<<<<<<< HEAD
class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def insert_head(head, data):
	if head == None:
		return Node(data)
	else:
		new_node = Node(data)
		new_node.next = head
		head = new_node
		return head

def display(head):
	ptr = head
	while ptr:
		print(ptr.data, end="->")
		ptr = ptr.next
	print()

def mid_pt(head): # Tortoise and hare approach; Time Complexity: O(n), Space Complexity: O(1)
	if head ==None:
		return -1
	slow = head
	fast = head.next
	while fast and fast.next:
		slow = slow.next
		fast = fast.next.next
	return slow.data

head = None
li = [int(x) for x in input().split()]
for ele in li:
	head = insert_head(head, ele)
display(head)
=======
class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def insert_head(head, data):
	if head == None:
		return Node(data)
	else:
		new_node = Node(data)
		new_node.next = head
		head = new_node
		return head

def display(head):
	ptr = head
	while ptr:
		print(ptr.data, end="->")
		ptr = ptr.next
	print()

def mid_pt(head): # Tortoise and hare approach; Time Complexity: O(n), Space Complexity: O(1)
	if head ==None:
		return -1
	slow = head
	fast = head.next
	while fast and fast.next:
		slow = slow.next
		fast = fast.next.next
	return slow.data

head = None
li = [int(x) for x in input().split()]
for ele in li:
	head = insert_head(head, ele)
display(head)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print("Mid Node: ", mid_pt(head))