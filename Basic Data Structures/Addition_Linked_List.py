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

def add(head1, head2):
	st1 = []
	st2 = []
	ptr = head1
	while ptr:
		st1.append(ptr.data)
		ptr = ptr.next
	ptr = head2
	while ptr:
		st2.append(ptr.data)
		ptr = ptr.next
	new_head = None
	carry = 0
	while len(st1) and len(st2):
		d = st1.pop()+st2.pop()+carry
		new_head = insert_head(new_head, (d%10))
		carry = d//10
	while len(st1):
		d = st1.pop()+carry
		new_head = insert_head(new_head, d%10)
		carry = d//10
	while len(st2):
		d = st2.pop()+carry
		new_head = insert_head(new_head, d%10)
		carry = d//10
	if carry > 0:
		new_head = insert_head(new_head, carry)
	return new_head

head1, head2 = None, None
head1 = insert_head(head1, 4)
head1 = insert_head(head1, 3)
head1 = insert_head(head1, 2)
head1 = insert_head(head1, 1)
display(head1)
head2 = insert_head(head2, 9)
head2 = insert_head(head2, 1)
head2 = insert_head(head2, 8)
head2 = insert_head(head2, 9)
display(head2)
added_ll = add(head1, head2)
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

def add(head1, head2):
	st1 = []
	st2 = []
	ptr = head1
	while ptr:
		st1.append(ptr.data)
		ptr = ptr.next
	ptr = head2
	while ptr:
		st2.append(ptr.data)
		ptr = ptr.next
	new_head = None
	carry = 0
	while len(st1) and len(st2):
		d = st1.pop()+st2.pop()+carry
		new_head = insert_head(new_head, (d%10))
		carry = d//10
	while len(st1):
		d = st1.pop()+carry
		new_head = insert_head(new_head, d%10)
		carry = d//10
	while len(st2):
		d = st2.pop()+carry
		new_head = insert_head(new_head, d%10)
		carry = d//10
	if carry > 0:
		new_head = insert_head(new_head, carry)
	return new_head

head1, head2 = None, None
head1 = insert_head(head1, 4)
head1 = insert_head(head1, 3)
head1 = insert_head(head1, 2)
head1 = insert_head(head1, 1)
display(head1)
head2 = insert_head(head2, 9)
head2 = insert_head(head2, 1)
head2 = insert_head(head2, 8)
head2 = insert_head(head2, 9)
display(head2)
added_ll = add(head1, head2)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
display(added_ll)