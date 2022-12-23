#include <bits/stdc++.h>
#define ll long long int

void subseq(std::string str, std::string output){
    if(str == "") {std::cout<<output<<", ";return;}//base case
    std::string x=str.substr(1);
    subseq(x, output+str[0]);
    subseq(x, output);
}
int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::string str;
    std::cin>>str;
    subseq(str, "");
    
	return 0;
}
