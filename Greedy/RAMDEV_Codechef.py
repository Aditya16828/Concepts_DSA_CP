l, b = [int(x) for x in input().split()]
n = int(input())
ans = 0
for i in range(n):
	L, B = [int(x) for x in input().split()]
	ans += max((L//l)*(B//b), (L//b)*(B//l))
print(ans)