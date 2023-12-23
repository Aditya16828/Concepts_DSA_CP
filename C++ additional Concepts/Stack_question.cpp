/*
Given a string A and an integer B. A is encoded and consists of lowercase English alphabets and numbers.
A is encoded in a way that where repetitions of substring is as substring followed by the count.
Find the Bth character of the decoded string.

Example:
    A = ab2c3
    B = 8
    Explanation:
        string is A = ababcababcababc 
        ans -> 'a'

Approach:
    The characters after the Bth character is useless for me.
    Now, lets look at the last integer at the end of the string,
    the resultant string is the repetition of previous string of len = 5.
    So, character at B%5(= 3) of the 5 len string is our ans.
    Now, that 5 len string is also formed by expansion of "ab" 2 times.
    So, character at B%2 = (3%2 = 1) of the 2 length string "ab" is the ans.

    Hence, we can maintain a stack of <char, int> where 
    int -> length of string when that character appears as the last character in the string.
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

void file_i_o() {
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int len = 0;
    std::stack<std::pair<char, int>> st;
    std::string A;
    int B;
    std::cin>>A;
    std::cin>>B;
    for(int i=0;i<A.size();i++){
        if(A[i] >= 'a' and A[i] <= 'z'){
            len += 1;
            st.push(std::make_pair(A[i], len));
        } else {
            len *= (A[i]-'0');
        }
    }
    char ans;
    while(not st.empty()){
        std::pair<char, int> temp = st.top();
        B %= temp.second;
        if(B == 0){
            ans = temp.first;
            break;
        }
        st.pop();
    }
    std::cout<<ans<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
