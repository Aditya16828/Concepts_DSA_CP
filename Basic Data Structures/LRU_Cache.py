<<<<<<< HEAD
class Node:
	data = -1
	next = None
	prev = None

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
			return temp
		else:
			new_node = Node(data)
			new_node.next = self.head
			self.head.prev = new_node
			self.head = new_node
			self.size += 1
			return new_node

	def insert_tail(self, data):
		if self.head == None:
			temp = Node(data)
			self.head, self.tail = temp, temp
			self.head.next = self.tail
			self.tail.prev = self.head
			self.size += 1
			return temp
		else:
			new_node = Node(data)
			new_node.prev = self.tail
			self.tail.next = new_node
			self.tail = new_node
			self.size += 1
			return new_node

	def remove_node(self, node):
		temp = node
		node.prev.next = node.next
		node.next.prev = node.prev
		node.next = None
		node.prev = None
		self.size -= 1
		return temp

	def remove_tail(self):
		if self.head == None:
			return None
		temp = self.tail
		self.tail = temp.prev
		temp.prev = None
		return temp

	def find(self, key):
		if self.head == None:
			return None
		else:
			temp = self.head
			while temp:
				if temp.data == key:
					return temp
				temp = temp.next

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

class LRUCache:
	max_capacity = 0
	size = 0
	mp_kv = {}
	mp_knode = {}
	dll = DLL()

	def __init__(self, capacity):
		self.max_capacity = capacity
		size = 0
		mp_kv = {}
		mp_knode = {}
		self.dll = DLL()

	def get(self, key):
		if key in self.mp_kv:
			removed_node = self.dll.remove_node(self.mp_knode[key])
			x = self.dll.insert_head(removed_node.data)
			self.mp_knode[key] = x
			return self.mp_kv[key]
		else:
			return -1

	def put(self, key, value):
		if self.size < self.max_capacity:
			if key in self.mp_kv:
				removed_node = self.dll.remove_node(self.mp_knode[key])
				node = self.dll.insert_head(key)
				self.mp_kv[key] = value
				self.mp_knode[key] = node
			else:
				node = self.dll.insert_head(key)
				self.mp_kv[key] = value
				self.mp_knode[key] = node
				self.size += 1
		else:
			removed_node = self.dll.remove_tail()
			del self.mp_kv[removed_node.data]
			del self.mp_knode[removed_node.data]
			node = self.dll.insert_head(key)
			self.mp_kv[key] = value
			self.mp_knode[key] = node

	def display_LL(self):
		self.dll.display()

lRUCache = LRUCache(2);
"""print(lRUCache.mp_kv)
print(lRUCache.mp_knode)
print(lRUCache.size)
print(lRUCache.max_capacity)"""
lRUCache.put(1, 1); # cache is {1=1}
lRUCache.put(2, 2); # cache is {1=1, 2=2}
print(lRUCache.mp_kv)
print(lRUCache.get(1));    # return 1
lRUCache.put(3, 3); # LRU key was 2, evicts key 2, cache is {1=1, 3=3}
print(lRUCache.mp_kv)
print(lRUCache.get(2));    # returns -1 (not found)
lRUCache.put(4, 4); # LRU key was 1, evicts key 1, cache is {4=4, 3=3}
print(lRUCache.get(1));    # return -1 (not found)
print(lRUCache.get(3));    # return 3
=======
class Node:
	data = -1
	next = None
	prev = None

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
			return temp
		else:
			new_node = Node(data)
			new_node.next = self.head
			self.head.prev = new_node
			self.head = new_node
			self.size += 1
			return new_node

	def insert_tail(self, data):
		if self.head == None:
			temp = Node(data)
			self.head, self.tail = temp, temp
			self.head.next = self.tail
			self.tail.prev = self.head
			self.size += 1
			return temp
		else:
			new_node = Node(data)
			new_node.prev = self.tail
			self.tail.next = new_node
			self.tail = new_node
			self.size += 1
			return new_node

	def remove_node(self, node):
		temp = node
		node.prev.next = node.next
		node.next.prev = node.prev
		node.next = None
		node.prev = None
		self.size -= 1
		return temp

	def remove_tail(self):
		if self.head == None:
			return None
		temp = self.tail
		self.tail = temp.prev
		temp.prev = None
		return temp

	def find(self, key):
		if self.head == None:
			return None
		else:
			temp = self.head
			while temp:
				if temp.data == key:
					return temp
				temp = temp.next

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

class LRUCache:
	max_capacity = 0
	size = 0
	mp_kv = {}
	mp_knode = {}
	dll = DLL()

	def __init__(self, capacity):
		self.max_capacity = capacity
		size = 0
		mp_kv = {}
		mp_knode = {}
		self.dll = DLL()

	def get(self, key):
		if key in self.mp_kv:
			removed_node = self.dll.remove_node(self.mp_knode[key])
			x = self.dll.insert_head(removed_node.data)
			self.mp_knode[key] = x
			return self.mp_kv[key]
		else:
			return -1

	def put(self, key, value):
		if self.size < self.max_capacity:
			if key in self.mp_kv:
				removed_node = self.dll.remove_node(self.mp_knode[key])
				node = self.dll.insert_head(key)
				self.mp_kv[key] = value
				self.mp_knode[key] = node
			else:
				node = self.dll.insert_head(key)
				self.mp_kv[key] = value
				self.mp_knode[key] = node
				self.size += 1
		else:
			removed_node = self.dll.remove_tail()
			del self.mp_kv[removed_node.data]
			del self.mp_knode[removed_node.data]
			node = self.dll.insert_head(key)
			self.mp_kv[key] = value
			self.mp_knode[key] = node

	def display_LL(self):
		self.dll.display()

lRUCache = LRUCache(2);
"""print(lRUCache.mp_kv)
print(lRUCache.mp_knode)
print(lRUCache.size)
print(lRUCache.max_capacity)"""
lRUCache.put(1, 1); # cache is {1=1}
lRUCache.put(2, 2); # cache is {1=1, 2=2}
print(lRUCache.mp_kv)
print(lRUCache.get(1));    # return 1
lRUCache.put(3, 3); # LRU key was 2, evicts key 2, cache is {1=1, 3=3}
print(lRUCache.mp_kv)
print(lRUCache.get(2));    # returns -1 (not found)
lRUCache.put(4, 4); # LRU key was 1, evicts key 1, cache is {4=4, 3=3}
print(lRUCache.get(1));    # return -1 (not found)
print(lRUCache.get(3));    # return 3
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(lRUCache.get(4));    # return 4