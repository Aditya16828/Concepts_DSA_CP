"""
Q. You will be given a string of balenced parenthesis, compute the score of the string.
	() -> score=1
	(()) -> score=2
Logic: 
	A (A is a string of parenthesis) -> score=x
	(A) -> score = 2x
	AB -> score = score A + score B
"""

def score(str):
    st = []
    n = len(str)
    for i in range(0, n):
        if str[i] == '(':
            st.append(0)
        elif str[i] == ')':
            top = st[-1]
            st.pop()
            if top == 0:
                st.append(1)
            else:
                st.append(2*top)
    ans = 0
    for i in range(0, len(st)):
        ans += st[i]
    return ans

prn = input()
print(score(prn))