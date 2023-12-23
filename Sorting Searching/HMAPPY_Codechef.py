# https://www.codechef.com/problems/HMAPPY

def possible(max_candies, a, b, n, m):
    sum = 0
    for i in range(n):
        # sum of balloons in hand {reqd number of balloons - number of candies in place of balloons}
        sum += max(0, (a[i] - (max_candies//b[i])))
        if sum > m:
            return False
    return True


def solve(a, b, n, m):
    lo = 0
    sum = 0
    for i in range(n):
        sum += a[i]
    hi = max(b)*(sum-m)
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if possible(mid, a, b, n, m):
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans


n, m = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

print(solve(a, b, n, m))
