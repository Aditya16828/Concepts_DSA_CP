<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void gen_permut(std::string str, std::string output){
    if(str.size() == 0){
        std::cout<<output<<", ";
        return;
    }
    bool visited[26]={0};
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(!visited[ch-'a']){
            visited[ch-'a']=true;
            std::string rest=str.substr(0,i)+str.substr(i+1); // O(n)
            gen_permut(rest, output+ch); // O((n-1)!*n) 
        }
    }
}
// Time recurrence: T(n) = n*(n + T(n-1) + (n-1)!*n)

void gen_permut_op(std::string &str, int i){
    if(i == str.size()-1){
        std::cout<<str<<", ";
        return;
    }
    bool visited[26]={0};
    for(int j=i;j<str.length();j++){
        char ch=str[j];
        if(!visited[ch-'a']){
            visited[ch-'a']=true;
            std::swap(str[j], str[i]);
            gen_permut_op(str, i+1);
            std::swap(str[j], str[i]);
        }
    }
}
// Time Recurrence: T(n) = n*T(n-1)

int main(){
 clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s;
    std::cin>>s;
    //gen_permut(s, "");
    gen_permut_op(s, 0);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
  return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void gen_permut(std::string str, std::string output){
    if(str.size() == 0){
        std::cout<<output<<", ";
        return;
    }
    bool visited[26]={0};
    for(int i=0;i<str.size();i++){
        char ch=str[i];
        if(!visited[ch-'a']){
            visited[ch-'a']=true;
            std::string rest=str.substr(0,i)+str.substr(i+1); // O(n)
            gen_permut(rest, output+ch); // O((n-1)!*n) 
        }
    }
}
// Time recurrence: T(n) = n*(n + T(n-1) + (n-1)!*n)

void gen_permut_op(std::string &str, int i){
    if(i == str.size()-1){
        std::cout<<str<<", ";
        return;
    }
    bool visited[26]={0};
    for(int j=i;j<str.length();j++){
        char ch=str[j];
        if(!visited[ch-'a']){
            visited[ch-'a']=true;
            std::swap(str[j], str[i]);
            gen_permut_op(str, i+1);
            std::swap(str[j], str[i]);
        }
    }
}
// Time Recurrence: T(n) = n*T(n-1)

int main(){
 clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string s;
    std::cin>>s;
    //gen_permut(s, "");
    gen_permut_op(s, 0);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
  return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}