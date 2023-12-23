<<<<<<< HEAD
l, b = [int(x) for x in input().split()]
n = int(input())
ans = 0
for i in range(n):
	L, B = [int(x) for x in input().split()]
	ans += max((L//l)*(B//b), (L//b)*(B//l))
=======
l, b = [int(x) for x in input().split()]
n = int(input())
ans = 0
for i in range(n):
	L, B = [int(x) for x in input().split()]
	ans += max((L//l)*(B//b), (L//b)*(B//l))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(ans)