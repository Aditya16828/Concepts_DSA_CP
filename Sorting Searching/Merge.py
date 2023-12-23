<<<<<<< HEAD
def merge(left, right):
    l=0
    r=0
    nl = len(left)
    nr = len(right)
    res = []
    while l < nl and r < nr:
        if(left[l] < right[r]):
            res.append(left[l])
            l += 1
        else:
            res.append(right[r])
            r += 1
    while l < nl:
        res.append(left[l])
        l += 1
    while r < nr:
        res.append(right[r])
        r += 1
    return res

arr_left = [1, 2, 3, 4]
arr_right = [5, 6, 7, 8, 9]
=======
def merge(left, right):
    l=0
    r=0
    nl = len(left)
    nr = len(right)
    res = []
    while l < nl and r < nr:
        if(left[l] < right[r]):
            res.append(left[l])
            l += 1
        else:
            res.append(right[r])
            r += 1
    while l < nl:
        res.append(left[l])
        l += 1
    while r < nr:
        res.append(right[r])
        r += 1
    return res

arr_left = [1, 2, 3, 4]
arr_right = [5, 6, 7, 8, 9]
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
print(merge(arr_left, arr_right))   