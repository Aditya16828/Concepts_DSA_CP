"""
Q. You went to a photocopy shop having 2 machines. First machine takes x sec to copy one sheet and other takes  y sec. 
Both can be used parallely.  You have a piece of paper for which you need n copies. Find the minimum time required
"""


def isPossible(mid, x, y, n):
    return (mid//x + mid//y) >= (n-1)


def photocopy(x, y, n):
    if n == 1:
        return min(x, y)
    lo, hi = 0, max(x, y)*(n-1)
    ans = 0
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if isPossible(mid, x, y, n):
            hi = mid-1
            ans = hi
        else:
            lo = mid+1
    return ans
