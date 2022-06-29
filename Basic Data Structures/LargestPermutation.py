# https://www.hackerrank.com/challenges/largest-permutation/problem
def permute(li, k):
    reqd_idx = {}
    original_idx = {}
    for i in range(0, len(li)):
        original_idx[li[i]] = i
    for i in range(0, n):
        reqd_idx[n-i] = i
    for ele in reqd_idx.keys():
        if reqd_idx[ele] == original_idx[ele]:
            continue
        else:
            oidx = original_idx[ele]
            ridx = reqd_idx[ele]
            x = li[ridx]
            y = li[oidx]
            li[ridx], li[oidx] = li[oidx], li[ridx]
            original_idx[x], original_idx[y] = original_idx[y], original_idx[x]
            k -= 1
        if k == 0:
            break
    return li

def display(arr):
    for ele in arr:
        print(ele, end = " ")
    print()

li = [int(x) for x in input().split()]
n = li[0]
k = li[1]
arr = [int(x) for x in input().split()]
arr = permute(arr, k)
display(arr)