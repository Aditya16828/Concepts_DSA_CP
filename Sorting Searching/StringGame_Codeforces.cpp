<<<<<<< HEAD
// https://codeforces.com/problemset/problem/778/A
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

bool possible(int to_del, std::vector<int> &arr, std::string t, std::string p){
    std::unordered_set<int> s; // search in O(1)
    for(int i=0;i<to_del;i++){
        s.insert(arr[i]-1);
    }
    // make a string by deleting the given indices
    std::string temp = "";
    for(int i=0;i<t.size();i++){
        if(s.count(i) == 0){
            temp += t[i];
        }
    }

    // confirm whether that temp string can be used to make string p:
    int i=0, j=0;
    while(i<temp.size() and j<p.size()){
        if(temp[i] == p[j]){
            j += 1;
            i += 1;
        } else {
            i += 1;
        }
    }
    return j == p.size();
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    std::string t, p;
    std::cin>>t>>p;
    std::vector<int> a(t.size());
    for(int i=0;i<t.size();i++){std::cin>>a[i];}
    // find out maximum number of letter than nastya can remove.
    int lo =0, hi = t.size()-p.size(), ans = -1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if (possible(mid, a, t, p)){
            ans = mid;
            lo = mid+1;
        } else hi = mid-1;
    }
    std::cout<<ans<<"\n";
    
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
=======
// https://codeforces.com/problemset/problem/778/A
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

bool possible(int to_del, std::vector<int> &arr, std::string t, std::string p){
    std::unordered_set<int> s; // search in O(1)
    for(int i=0;i<to_del;i++){
        s.insert(arr[i]-1);
    }
    // make a string by deleting the given indices
    std::string temp = "";
    for(int i=0;i<t.size();i++){
        if(s.count(i) == 0){
            temp += t[i];
        }
    }

    // confirm whether that temp string can be used to make string p:
    int i=0, j=0;
    while(i<temp.size() and j<p.size()){
        if(temp[i] == p[j]){
            j += 1;
            i += 1;
        } else {
            i += 1;
        }
    }
    return j == p.size();
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    std::string t, p;
    std::cin>>t>>p;
    std::vector<int> a(t.size());
    for(int i=0;i<t.size();i++){std::cin>>a[i];}
    // find out maximum number of letter than nastya can remove.
    int lo =0, hi = t.size()-p.size(), ans = -1;
    while(lo <= hi){
        int mid = lo + (hi-lo)/2;
        if (possible(mid, a, t, p)){
            ans = mid;
            lo = mid+1;
        } else hi = mid-1;
    }
    std::cout<<ans<<"\n";
    
    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
