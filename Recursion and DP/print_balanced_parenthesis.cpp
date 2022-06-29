#include <bits/stdc++.h>
#define ll long long int

std::vector<std::string> par;
void gen_parenthesis(int open, int close, std::string output, int n){
    if(close==n){
        std::cout<<output<<"\n";
        return;
    }
    if(open<n){
        gen_parenthesis(open+1, close, output+"(", n);
    }
    if(open>close){
        gen_parenthesis(open, close+1, output+")", n);
    }
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin>>n;
    gen_parenthesis(0, 0, "", n);
    
	return 0;
}
