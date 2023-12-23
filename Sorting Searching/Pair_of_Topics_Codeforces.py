<<<<<<< HEAD
# https://codeforces.com/contest/1324/problem/D?f0a28=1
"""
equation:
    a[i] - b[i] > a[j] - b[j] => c[i] > -c[j]
Now, create an array c = a[i]-b[i]
Now, we have an array c, pick any c[j]; we need to find c[i] > -c[j] for i < j.
    c1 c2 c3 ... ci ... cj ... cn
"""


def upper_bound(start, end, target, arr):
    lo, hi = start, end
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if arr[mid] > target:
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans


def solve(a, b, n):
    c = []
    for i in range(0, n):
        c.append(a[i]-b[i])
    c.sort()
    ans = 0
    # print(c)
    for j in range(1, len(c)):
        cj = -c[j]
        idx = upper_bound(0, j-1, cj, c)
        #print("idx :", idx)
        if idx > -1:
            ans += (j-1 - idx+1)
    return ans


n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
print(solve(a, b, n))

# -(-2) less than any of the before elements
# number of elements greater than -(-2) before its own index
=======
# https://codeforces.com/contest/1324/problem/D?f0a28=1
"""
equation:
    a[i] - b[i] > a[j] - b[j] => c[i] > -c[j]
Now, create an array c = a[i]-b[i]
Now, we have an array c, pick any c[j]; we need to find c[i] > -c[j] for i < j.
    c1 c2 c3 ... ci ... cj ... cn
"""


def upper_bound(start, end, target, arr):
    lo, hi = start, end
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if arr[mid] > target:
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans


def solve(a, b, n):
    c = []
    for i in range(0, n):
        c.append(a[i]-b[i])
    c.sort()
    ans = 0
    # print(c)
    for j in range(1, len(c)):
        cj = -c[j]
        idx = upper_bound(0, j-1, cj, c)
        #print("idx :", idx)
        if idx > -1:
            ans += (j-1 - idx+1)
    return ans


n = int(input())
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
print(solve(a, b, n))

# -(-2) less than any of the before elements
# number of elements greater than -(-2) before its own index
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
