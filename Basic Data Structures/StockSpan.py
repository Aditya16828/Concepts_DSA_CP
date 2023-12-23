#Problem Statement: You've been given daily price quates for a stock and 
# we need to calculate span of the stock for all n days.
# Span: Span on any day i is defined as number of consecutive days just before the given day for 
# which price was less than or equal to the price in the ith day.
# example: [100, 80, 60, 70, 60, 75, 85]
# ans: [1, 1, 1, 2, 1, 4, 6]
# Solution strategy: Find for just larger element in the back of a[i]

def stock_span(li):
    n = len(li)
    st = []
    res = [1]*n
    st.append(0)
    for i in range(1, n):
        while not len(st) == 0 and li[st[-1]] <= li[i]:
            st.pop()
        if len(st) == 0:
            res[i] = i+1 # that element is smaller than all the elements in the back
        else:
            res[i] = i - li[st[-1]] # finding the number of elements that are smaller than li[i]
        st.append(i)