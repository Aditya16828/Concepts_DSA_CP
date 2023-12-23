<<<<<<< HEAD
def possible(mid, n, x, y):
    return (mid//x) + (mid//y) >= (n-1)

def printing_copies(n, x, y):
    # O(log(max(x, y)*n))
    if n == 1:
        return min(x, y)
    
    lo, hi = 0, max(x, y)*n 
    ans = 0
    while lo <= hi:
        mid = lo + (hi - lo)//2 
        if possible(mid, n, x, y):
            ans = mid 
            hi = mid - 1
        else:
            lo = mid + 1
    return ans + min(x, y)

n, x, y = [int(x) for x in input().split()]
=======
def possible(mid, n, x, y):
    return (mid//x) + (mid//y) >= (n-1)

def printing_copies(n, x, y):
    # O(log(max(x, y)*n))
    if n == 1:
        return min(x, y)
    
    lo, hi = 0, max(x, y)*n 
    ans = 0
    while lo <= hi:
        mid = lo + (hi - lo)//2 
        if possible(mid, n, x, y):
            ans = mid 
            hi = mid - 1
        else:
            lo = mid + 1
    return ans + min(x, y)

n, x, y = [int(x) for x in input().split()]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(printing_copies(n, x, y))