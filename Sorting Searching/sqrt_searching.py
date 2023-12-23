<<<<<<< HEAD
def sqrt(n):
    if n == 0 or n == 1:
        return n
    lo, hi, ans = 0, n, n
    while lo <= hi:
        mid = lo + ((hi - lo)//2)
        if mid*mid == n:
            return mid
        elif mid*mid < n:
            # discard left half
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return ans


n = int(input())
print(sqrt(n))
=======
def sqrt(n):
    if n == 0 or n == 1:
        return n
    lo, hi, ans = 0, n, n
    while lo <= hi:
        mid = lo + ((hi - lo)//2)
        if mid*mid == n:
            return mid
        elif mid*mid < n:
            # discard left half
            ans = mid
            lo = mid + 1
        else:
            hi = mid - 1
    return ans


n = int(input())
print(sqrt(n))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
