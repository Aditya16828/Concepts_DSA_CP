<<<<<<< HEAD
# x^2 + sqrt(x) = c
def calc(c):
    l, r = 1, 1e10
    mid = 0.0
    for _ in range(1, 150):
        mid = l + (r - l)/2
        if mid*mid + mid**0.5 == c:
            return mid 
        elif mid*mid + mid**0.5 > c:
            r = mid 
        else:
            l = mid 
    return mid

c = float(input())
ans = calc(c)

=======
# x^2 + sqrt(x) = c
def calc(c):
    l, r = 1, 1e10
    mid = 0.0
    for _ in range(1, 150):
        mid = l + (r - l)/2
        if mid*mid + mid**0.5 == c:
            return mid 
        elif mid*mid + mid**0.5 > c:
            r = mid 
        else:
            l = mid 
    return mid

c = float(input())
ans = calc(c)

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print("%0.6f"%ans)