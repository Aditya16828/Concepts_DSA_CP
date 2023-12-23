<<<<<<< HEAD
# https://www.codechef.com/LTIME93B/problems/PALPALS
t = int(input())
while t:
	s = input()
	frq = [0]*26
	for i in range(len(s)):
		frq[ord(s[i])-97] += 1
	odd = 0
	for f in range(26):
		if frq[f] % 2 != 0:
			odd += 1
	pairs = (len(s)-odd) // 2
	if pairs < odd:
		print("NO")
	else:
		print("YES")
=======
# https://www.codechef.com/LTIME93B/problems/PALPALS
t = int(input())
while t:
	s = input()
	frq = [0]*26
	for i in range(len(s)):
		frq[ord(s[i])-97] += 1
	odd = 0
	for f in range(26):
		if frq[f] % 2 != 0:
			odd += 1
	pairs = (len(s)-odd) // 2
	if pairs < odd:
		print("NO")
	else:
		print("YES")
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
	t -= 1