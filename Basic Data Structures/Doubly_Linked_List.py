class Node:
	data = -1
	next, prev = None, None

	def __init__(self, d):
		self.data = d
		self.next = None
		self.prev = None

class DLL:
	head = None
	tail = None
	size = 0

	def __init__(self):
		self.head, self.tail = None, None
		self.size = 0

	def insert_head(self, data):
		if self.head == None:
			temp = Node(data)
			self.head, self.tail = temp, temp
			self.head.next = self.tail
			self.tail.prev = self.head
			self.size += 1
		else:
			new_node = Node(data)
			new_node.next = self.head
			self.head.prev = new_node
			self.head = new_node
			self.size += 1

	def insert_tail(self, data):
		if self.head == None:
			temp = Node(data)
			self.head, self.tail = temp, temp
			self.head.next = self.tail
			self.tail.prev = self.head
			self.size += 1
		else:
			new_node = Node(data)
			new_node.prev = self.tail
			self.tail.next = new_node
			self.tail = new_node
			self.size += 1

	def remove_node(self, node):
		if node == None:
			return self.head
		temp = node
		node.prev.next = node.next
		node.next.prev = node.prev
		node.next = None
		node.prev = None
		self.size -= 1

	def remove_tail(self):
		temp = self.tail
		self.tail = self.tail.prev
		self.tail.next.prev = None
		self.tail.next = None

	def find(self, key):
		if self.head == None:
			return None
		else:
			temp = self.head
			while temp:
				if temp.data == key:
					return temp
				temp = temp.next
			return None

	def len(self):
		return self.size

	def display(self):
		if self.head == None:
			return
		else:
			temp = self.head
			while temp:
				print(temp.data, end = " ")
				temp = temp.next
			print()

dll = DLL()
dll.insert_head(2)
dll.insert_head(3)
dll.insert_head(7)
dll.insert_head(1)
dll.insert_tail(90)
dll.insert_tail(78)
dll.insert_tail(23)
dll.display()
dll.remove_tail()
dll.display()
dll.remove_node(dll.find(3))
dll.display()