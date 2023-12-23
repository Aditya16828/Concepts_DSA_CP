<<<<<<< HEAD
# https://www.spoj.com/problems/AGGRCOW/

def possible(dist, loc, cows):
    n = len(loc)
    last_loc = loc[0]
    cnt = 1
    for i in range(1, n):
        if (loc[i]-last_loc) >= dist:
            cnt += 1
            last_loc = loc[i]
        if cnt >= cows:
            return True
    return False


def solve():
    n, c = [int(x) for x in input().split()]
    loc = []
    for i in range(n):
        l = int(input())
        loc.append(l)
    loc.sort()
    lo = loc[1]-loc[0]
    hi = loc[len(loc) - 1] - loc[0]
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if possible(mid, loc, c):
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    return ans


t = int(input())
for test in range(t):
    print(solve())
=======
# https://www.spoj.com/problems/AGGRCOW/

def possible(dist, loc, cows):
    n = len(loc)
    last_loc = loc[0]
    cnt = 1
    for i in range(1, n):
        if (loc[i]-last_loc) >= dist:
            cnt += 1
            last_loc = loc[i]
        if cnt >= cows:
            return True
    return False


def solve():
    n, c = [int(x) for x in input().split()]
    loc = []
    for i in range(n):
        l = int(input())
        loc.append(l)
    loc.sort()
    lo = loc[1]-loc[0]
    hi = loc[len(loc) - 1] - loc[0]
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if possible(mid, loc, c):
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    return ans


t = int(input())
for test in range(t):
    print(solve())
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
