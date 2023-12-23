def maxStep(n):
    sum = 2*n
    lo = 1
    hi = n
    ans = 1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if mid*(mid+1) <= sum:
            ans = mid
            lo = mid+1
        else:
            hi = mid-1
    return ans


n = int(input())
print(maxStep(n))
