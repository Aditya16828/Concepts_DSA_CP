<<<<<<< HEAD
n = int(input())
li = [0]*n

q = int(input())

while q > 0:
	l, r = [int(x) for x in input().split()]
	li[l]+=1
	if r+1 < n:
		li[r+1]-=1

	q-=1


for i in range(1, len(li)):
	li[i] = li[i] + li[i-1]

=======
n = int(input())
li = [0]*n

q = int(input())

while q > 0:
	l, r = [int(x) for x in input().split()]
	li[l]+=1
	if r+1 < n:
		li[r+1]-=1

	q-=1


for i in range(1, len(li)):
	li[i] = li[i] + li[i-1]

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(li)