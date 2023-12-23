<<<<<<< HEAD
# https://www.spoj.com/problems/ANARC09A/
def min_replacements(str):
    st = []
    close = 0
    for i in range(0, len(str)):
        if str[i] == '{':
            st.append(str[i])
        else:
            if len(st) > 0:
                st.pop()
            else:
                close += 1
    ans = 0
    open = len(st)
    if (open > 0) and ((open % 2) == 1):
        ans += 2
        close -= 1
    
    ans += ((open//2) + (close//2))
    return ans

t = 1
while True:
    str = input().strip()
    if len(str) > 0 and str[0] == '-':
        break
    else:
        print(f"{t}. {min_replacements(str)}")
        t += 1

"""
*********C++ Code********
#include <bits/stdc++.h>
#define ll long long int

int min_rep(std::string str){
    std::stack<char> st;
    int n = str.size();
    int close = 0, open = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '{'){
            st.push('{');
        } else {
            if(not st.empty()){
                st.pop();
            } else {
                ++close;
            }
        }
    }
    int ans = 0;
    open = st.size();
    if(open%2 == 1){
        ans += 2;
        close--;
    }
    
    ans += (open/2 + close/2);
    return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t=1;
    while(true){
        std::string s;
        std::cin>>s;
        if(s.size() and s[0] == '-') break;
        else std::cout<<t<<". "<<min_rep(s)<<"\n";
        t++;
    }
    
	return 0;
}

=======
# https://www.spoj.com/problems/ANARC09A/
def min_replacements(str):
    st = []
    close = 0
    for i in range(0, len(str)):
        if str[i] == '{':
            st.append(str[i])
        else:
            if len(st) > 0:
                st.pop()
            else:
                close += 1
    ans = 0
    open = len(st)
    if (open > 0) and ((open % 2) == 1):
        ans += 2
        close -= 1
    
    ans += ((open//2) + (close//2))
    return ans

t = 1
while True:
    str = input().strip()
    if len(str) > 0 and str[0] == '-':
        break
    else:
        print(f"{t}. {min_replacements(str)}")
        t += 1

"""
*********C++ Code********
#include <bits/stdc++.h>
#define ll long long int

int min_rep(std::string str){
    std::stack<char> st;
    int n = str.size();
    int close = 0, open = 0;
    for(int i=0;i<n;i++){
        if(str[i] == '{'){
            st.push('{');
        } else {
            if(not st.empty()){
                st.pop();
            } else {
                ++close;
            }
        }
    }
    int ans = 0;
    open = st.size();
    if(open%2 == 1){
        ans += 2;
        close--;
    }
    
    ans += (open/2 + close/2);
    return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t=1;
    while(true){
        std::string s;
        std::cin>>s;
        if(s.size() and s[0] == '-') break;
        else std::cout<<t<<". "<<min_rep(s)<<"\n";
        t++;
    }
    
	return 0;
}

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
"""