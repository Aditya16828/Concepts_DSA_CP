def remove_duplicates(s):
	st = []
	vis = {}
	last_occ = {}
	for i in range(len(s)):
		last_occ[s[i]] = i

	for i in range(len(s)):
		if not vis.get(s[i]):
			while len(st) and s[i] < st[-1] and last_occ.get(st[-1]) > i:
				vis.pop(st[-1])
				st.pop()
			st.append(s[i])
			vis[s[i]] = True

	for ele in st:
		print(ele, end="")
	print()

str = input()
print("Original: ", str)
remove_duplicates(str)