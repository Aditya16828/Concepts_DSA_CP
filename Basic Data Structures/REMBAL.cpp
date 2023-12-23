// https://www.codechef.com/START37B/problems/REMBAL
#include <bits/stdc++.h>
#define ll long long int

std::pair<int, int> solve(std::string str){
    std::vector<std::pair<char, int>> st;
    int n = str.size();
    st.push_back({'s', -1});
    for(int i=0;i<n;i++){
        if(str[i] == ')' and st[(int)st.size()-1].first == '('){
            st.pop_back();
        } else {
            st.push_back({str[i], i});
        }
    }
    int ops = 0;
    st.push_back({'e', n});
    for(int i=0;i+1 < (int)st.size();i++){
        if(st[i+1].second != st[i].second + 1) ++ops;
    }
    return {(int)st.size()-2, ops};
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int t;
    std::cin>>t;
    while(t--){
        std::string s;
        std::cin>>s;
        //solve(s);
        std::pair<int, int> p = solve(s);
        std::cout<<p.first<<" "<<p.second<<"\n";
    }
    
	return 0;
}
