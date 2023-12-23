<<<<<<< HEAD
def isPossible(mid, w, h, n):
    return (mid//w) * (mid//h) >= n


def square(w, h, n):
    lo = 0
    hi = max(h, w)*n
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if isPossible(mid, w, h, n):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
    return ans


w, h, n = [int(x) for x in input().split()]
print(square(w, h, n))
=======
def isPossible(mid, w, h, n):
    return (mid//w) * (mid//h) >= n


def square(w, h, n):
    lo = 0
    hi = max(h, w)*n
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if isPossible(mid, w, h, n):
            hi = mid-1
            ans = mid
        else:
            lo = mid+1
    return ans


w, h, n = [int(x) for x in input().split()]
print(square(w, h, n))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
