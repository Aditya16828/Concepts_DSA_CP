<<<<<<< HEAD
"""
You are given a set of integers [-3810^4, 3*10^4], find the total no. of sextuples (a, b, c, d, e, f) that satisfy:
    (a*b + c)/d - e = f
"""
"""
Brute force:
    we will try and find all combinations of a, b, c, d, e, f that satisfy the above equation(d != 0).

The equation can be simplified as:
    (a*b + c)/d = f+e
    => a*b + = d*(f+e)
Now, problem reduces to:
    Find all possible pair of triplets => [(a, b, c), (d, e, f)]
calculate all possible triplets of (a, b, c) and calcualte all possible triplets of (f, e, d) {d != 0}
So, we will be having 2 arrays consisting of the triplets:
    A1 = {(triplets (a, b, c))} (a*b + c)
    A2 = {(triplets (d, e, f))} (d*(f+e))
for each value in A1 how many values are equal in A2.
=> far each A1[i] find how many values are equal in A2. => occurences of A1[i] in A2.
which means I can find the lowerbound index and upperbound index of A1[i] in A2.
"""


import bisect as bs
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)
lhs = []
rhs = []
for a in range(0, n):
    for b in range(0, n):
        for c in range(0, n):
            lhs.append(arr[a]*arr[b] + arr[c])
for d in range(0, n):
    for e in range(0, n):
        for f in range(0, n):
            if arr[d] == 0:
                continue
            rhs.append((arr[e]+arr[f])*arr[d])

lhs.sort()
rhs.sort()

ans = 0

for i in range(0, len(lhs)):
    li = bs.bisect_left(rhs, lhs[i])
    ri = bs.bisect_right(rhs, lhs[i])
    ans += (ri-li)
print(ans)
=======
"""
You are given a set of integers [-3810^4, 3*10^4], find the total no. of sextuples (a, b, c, d, e, f) that satisfy:
    (a*b + c)/d - e = f
"""
"""
Brute force:
    we will try and find all combinations of a, b, c, d, e, f that satisfy the above equation(d != 0).

The equation can be simplified as:
    (a*b + c)/d = f+e
    => a*b + = d*(f+e)
Now, problem reduces to:
    Find all possible pair of triplets => [(a, b, c), (d, e, f)]
calculate all possible triplets of (a, b, c) and calcualte all possible triplets of (f, e, d) {d != 0}
So, we will be having 2 arrays consisting of the triplets:
    A1 = {(triplets (a, b, c))} (a*b + c)
    A2 = {(triplets (d, e, f))} (d*(f+e))
for each value in A1 how many values are equal in A2.
=> far each A1[i] find how many values are equal in A2. => occurences of A1[i] in A2.
which means I can find the lowerbound index and upperbound index of A1[i] in A2.
"""


import bisect as bs
n = int(input())
arr = []
for i in range(n):
    x = int(input())
    arr.append(x)
lhs = []
rhs = []
for a in range(0, n):
    for b in range(0, n):
        for c in range(0, n):
            lhs.append(arr[a]*arr[b] + arr[c])
for d in range(0, n):
    for e in range(0, n):
        for f in range(0, n):
            if arr[d] == 0:
                continue
            rhs.append((arr[e]+arr[f])*arr[d])

lhs.sort()
rhs.sort()

ans = 0

for i in range(0, len(lhs)):
    li = bs.bisect_left(rhs, lhs[i])
    ri = bs.bisect_right(rhs, lhs[i])
    ans += (ri-li)
print(ans)
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
