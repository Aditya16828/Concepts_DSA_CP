"""
Why do we need Linked Lists?
-> with arrays there are 2 issues:
1. we need to give size of arrays(nota disadv with lists or vectors).
2. Arrays need contiguous memory Allocation.

Arrays doesn't consume the available memory efficiently.
So to optimise this we need Linked Lists.

Linked lists are linear datastructure that store one data element in an entity called as a Node and multiple such nodes are connected to form a chained list. The nodes are not required to be created in contiguous memory blocks, so LL never consumes contiguous memory block.

The first node of a LL is called Head; and the last node is called Tail.

Appications:
1. Previous and next page in browsers
2. Music playlist
3. Caching mechanisms
4. Hash-Map
(Important For Interviews)
"""

class Node:
	data = -1
	next = None

	def __init__(self, data):
		self.data = data

def len(head):
	if head == None:
		return 0
	temp = head
	l = 0
	while temp:
		l += 1
		temp = temp.next
	return l

def insert_head(head, data): # head is passed as reference
	if head == None:
		return Node(data)
	else:
		new_node = Node(data)
		new_node.next = head
		head = new_node
		return head

def insert_tail(head, data):
	if head == None:
		return Node(data)
	else:
		temp = head
		while temp.next:
			temp = temp.next

		new_node = Node(data)
		temp.next = new_node
		return head

def insert_at(head, data, pos = 0):
	if head == None:
		return Node(data)
	if(pos == 0):
		return insert_head(head, data)
	i = 0
	temp = head
	while i < pos-1 and temp:
		i += 1
		temp = temp.next
	if(temp == None):
		insert_tail(head, data   )
	new_node = Node(data)
	new_node.next = temp.next
	temp.next = new_node
	return head

def delete_head(head):
	if head == None:
		return None
	temp = head
	head = head.next
	temp.next = None

def delete_tail(head):
	if head == None:
		return None
	temp = head
	prev = None
	while temp.next:
		prev = temp
		temp = temp.next
	prev.next = None
	return head

def delete_at(head, pos = 0):
	if pos == 0:
		return delete_head(head)
	if pos >= len(head):
		return delete_tail(head)
	temp = head
	while pos != 1:
		pos -= 1
		temp = temp.next
	to_be_deleted = temp.next
	temp.next = temp.next.next
	to_be_deleted.next = None
	return head

def display(head):
	ptr = head
	while ptr:
		print(ptr.data, end="->")
		ptr = ptr.next
	print()

head = None
li = [int(x) for x in input().split()]
for ele in li:
	head = insert_head(head, ele)
display(head)
head = insert_at(head, 56, 2)
display(head)