<<<<<<< HEAD
"""
Q. You are given no. of pages in n books and we have m students.
Books are arranged in sorted order based on the no. of pages.
Divide the book among m students such that maximum pages a student has to read is minimized.

(Language Variation)
Q. You have a list of numbers, you need to divide them into K segments such that max sum on a segment is minimum possible.
"""


def possible(max_pages, m, arr):
    n = len(arr)
    count = 1
    pages = 0
    for i in range(0, n):
        if pages + arr[i] <= max_pages:
            pages += arr[i]
        else:
            pages = arr[i]
            count += 1
        if count > m:
            return False
    return True


def solve(arr, n, m):
    lo = max(arr)
    hi = sum(arr)
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if possible(mid, m, arr):
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans


n, m = [int(x) for x in input().split()]
arr = [int(i) for i in input().split()]
print(solve(arr, n, m))
# O(n*log(sum-max))
=======
"""
Q. You are given no. of pages in n books and we have m students.
Books are arranged in sorted order based on the no. of pages.
Divide the book among m students such that maximum pages a student has to read is minimized.

(Language Variation)
Q. You have a list of numbers, you need to divide them into K segments such that max sum on a segment is minimum possible.
"""


def possible(max_pages, m, arr):
    n = len(arr)
    count = 1
    pages = 0
    for i in range(0, n):
        if pages + arr[i] <= max_pages:
            pages += arr[i]
        else:
            pages = arr[i]
            count += 1
        if count > m:
            return False
    return True


def solve(arr, n, m):
    lo = max(arr)
    hi = sum(arr)
    ans = -1
    while lo <= hi:
        mid = lo + (hi-lo)//2
        if possible(mid, m, arr):
            ans = mid
            hi = mid-1
        else:
            lo = mid+1
    return ans


n, m = [int(x) for x in input().split()]
arr = [int(i) for i in input().split()]
print(solve(arr, n, m))
# O(n*log(sum-max))
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
