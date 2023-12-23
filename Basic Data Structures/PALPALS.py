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
	t -= 1