#include <bits/stdc++.h>
#define ll long long int

void gen_seq(int n, std::string output){
    if(n==1 or n==2) {
        if(n == 1){
            std::cout<<output+"1"<<"\n";
            std::cout<<output+"0"<<"\n";
        }
        if(n == 2){
            std::cout<<output+"10"<<"\n";
            std::cout<<output+"01"<<"\n";
            std::cout<<output+"00"<<"\n";
        }
        return;
    }
    gen_seq(n-1, "0"+output);
    gen_seq(n-2, "10"+output);
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;
    std::cin>>n;
    gen_seq(n, "");
    
	return 0;
}
