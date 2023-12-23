<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int

void pattern(int i, int j){
    if(i==5) return;
    if(i == j){
        std::cout<<"*\n";
        pattern(i+1, 1);
        return;
    }
    std::cout<<"*";
    pattern(i, j+1);
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    pattern(1, 1);
    
	return 0;
}
=======
#include <bits/stdc++.h>
#define ll long long int

void pattern(int i, int j){
    if(i==5) return;
    if(i == j){
        std::cout<<"*\n";
        pattern(i+1, 1);
        return;
    }
    std::cout<<"*";
    pattern(i, j+1);
}

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    pattern(1, 1);
    
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
