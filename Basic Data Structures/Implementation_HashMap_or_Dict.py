<<<<<<< HEAD
class Node:
	key = ""
	value = 0
	next = None
	
	def __init__(self, key, value):
		self.key = key
		self.value = value

class HashTable:
	cs = 0
	ts = 1
	arr = []
	def __init__(self, ts):
		self.ts = ts
		self.arr = [None]*ts
		
	def hash_func(self, key):
		sum = 0
		factor = 1
		for i in range(len(key)):
			sum = (sum%self.ts + (ord(key[i])*factor)%self.ts)%self.ts
			factor = ((factor%self.ts) * (37%self.ts))%self.ts;
		return sum
	
	def rehash(self):
		old_size = self.ts
		self.ts *= 2
		self.cs = 0
		li = [Node] * self.ts
		for i in range(old_size):
			temp = self.arr[i]
			while temp != None:
				self.insert(temp.key, temp.value)
				temp = temp.next
	
	def insert(self, key, value):
		bi = self.hash_func(key)
		node = Node(key, value)
		if self.arr[bi] == Node:
			self.arr[bi] = node
		else:
			#collision
			node.next = self.arr[bi]
			self.arr[bi] = node
		self.cs += 1
		load_factor = self.cs/self.ts
		if load_factor > 0.5:
			self.rehash()
	
	def search(self, key):
		bi = self.hash_func(key)
		temp = self.arr[bi]
		while temp != None:
			if temp.key == key:
				return temp.value
			temp = temp.next
		return None
	
	def update(self, key, value):
		if self.search(key) == None:
			return False
		bi = self.hash_func(key)
		temp = self.arr[bi]
		while temp != None:
			if temp.key == key:
				temp.value = value
			temp = temp.next
		return True
	
	def display(self):
		for i in range(self.ts):
			temp = self.arr[i]
			if temp == None:
				print("Empty")
			else:
				while temp != None:
					print(f"key: {temp.key} -> value: {temp.value}")
					temp = temp.next
				print()


hashmap = HashTable(2)
hashmap.insert("aditya", 232)
hashmap.insert("adity", 1723)
hasmap.insert("apple", 8)
hasmap.insert("appy", 4)
hasmap.insert("applepie", 23)
hasmap.display()
=======
class Node:
	key = ""
	value = 0
	next = None
	
	def __init__(self, key, value):
		self.key = key
		self.value = value

class HashTable:
	cs = 0
	ts = 1
	arr = []
	def __init__(self, ts):
		self.ts = ts
		self.arr = [None]*ts
		
	def hash_func(self, key):
		sum = 0
		factor = 1
		for i in range(len(key)):
			sum = (sum%self.ts + (ord(key[i])*factor)%self.ts)%self.ts
			factor = ((factor%self.ts) * (37%self.ts))%self.ts;
		return sum
	
	def rehash(self):
		old_size = self.ts
		self.ts *= 2
		self.cs = 0
		li = [Node] * self.ts
		for i in range(old_size):
			temp = self.arr[i]
			while temp != None:
				self.insert(temp.key, temp.value)
				temp = temp.next
	
	def insert(self, key, value):
		bi = self.hash_func(key)
		node = Node(key, value)
		if self.arr[bi] == Node:
			self.arr[bi] = node
		else:
			#collision
			node.next = self.arr[bi]
			self.arr[bi] = node
		self.cs += 1
		load_factor = self.cs/self.ts
		if load_factor > 0.5:
			self.rehash()
	
	def search(self, key):
		bi = self.hash_func(key)
		temp = self.arr[bi]
		while temp != None:
			if temp.key == key:
				return temp.value
			temp = temp.next
		return None
	
	def update(self, key, value):
		if self.search(key) == None:
			return False
		bi = self.hash_func(key)
		temp = self.arr[bi]
		while temp != None:
			if temp.key == key:
				temp.value = value
			temp = temp.next
		return True
	
	def display(self):
		for i in range(self.ts):
			temp = self.arr[i]
			if temp == None:
				print("Empty")
			else:
				while temp != None:
					print(f"key: {temp.key} -> value: {temp.value}")
					temp = temp.next
				print()


hashmap = HashTable(2)
hashmap.insert("aditya", 232)
hashmap.insert("adity", 1723)
hasmap.insert("apple", 8)
hasmap.insert("appy", 4)
hasmap.insert("applepie", 23)
hasmap.display()
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
