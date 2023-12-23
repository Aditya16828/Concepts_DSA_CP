<<<<<<< HEAD
class Node:
	data = -1
	next = None
	prev = None

	def __init__(self, data):
		self.data = data

	def insert(self, head, data):
		if head == None:
			return Node(data)
		else:
			new_node = Node(data)
			new_node.next = head
			head = new_node
			return head

	def find(self, key):
		if head == None:
			return head
		temp = head
		while temp:
			if temp == key:
				return True
			temp = temp.next
		return False

	def remove(self, head, key):
		if head == None:
			return None
		elif self.find(key):
			prv_node = key.prev
			prv_node.next = key.next
			key.next.prev = prv_node
		return head

class LFUCache:
	max_capacity = 1
	mp_kv = {}

	def __init__(self, capacity):
		self.capacity = max_capacity

	def get(self, key):
		if key in mp_kv:
			return mp_kv.get(key)
		else:
			return -1

	def put(self, key, value):
=======
class Node:
	data = -1
	next = None
	prev = None

	def __init__(self, data):
		self.data = data

	def insert(self, head, data):
		if head == None:
			return Node(data)
		else:
			new_node = Node(data)
			new_node.next = head
			head = new_node
			return head

	def find(self, key):
		if head == None:
			return head
		temp = head
		while temp:
			if temp == key:
				return True
			temp = temp.next
		return False

	def remove(self, head, key):
		if head == None:
			return None
		elif self.find(key):
			prv_node = key.prev
			prv_node.next = key.next
			key.next.prev = prv_node
		return head

class LFUCache:
	max_capacity = 1
	mp_kv = {}

	def __init__(self, capacity):
		self.capacity = max_capacity

	def get(self, key):
		if key in mp_kv:
			return mp_kv.get(key)
		else:
			return -1

	def put(self, key, value):
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
		