<<<<<<< HEAD
// https://www.spoj.com/problems/PRATA/
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

ll f(ll k){
    return (k*k + k);
}

ll max_pratas(ll rank, ll time){
    ll lo = 0, hi = (2*time)/rank;
    ll ans = -1;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(f(mid) <= (2*time)/rank){
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

bool possible(ll p, ll time, std::vector<ll> &rank){
    // here we need to find the max pratas that ith cook can make; and sum of all i >= p or not.
    // let k is the number of pratas that ith cook can make:
    // the equation becomes: k^2 + k <= 2*time/rank[i]; rank[i] -> rank of ith cook
    ll sum_p = 0;
    for(int i=0;i<rank.size();i++){
        sum_p += max_pratas(rank[i], time);
    }
    return sum_p >= p;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--){
        ll p;
        std::cin>>p;
        ll l;
        std::cin>>l;
        std::vector<ll> li(l);
        for(ll i=0;i<l;i++) std::cin>>li[i];
        ll lo = 0, hi = ((p*(p+1))/2)*(*std::max_element(li.begin(), li.end())), ans = -1;
        // find the minimum time required to make p pratas.
        while(lo <= hi){
            ll mid = lo + (hi-lo)/2;
            if(possible(p, mid, li)){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        std::cout<<ans<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
=======
// https://www.spoj.com/problems/PRATA/
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

ll f(ll k){
    return (k*k + k);
}

ll max_pratas(ll rank, ll time){
    ll lo = 0, hi = (2*time)/rank;
    ll ans = -1;
    while(lo <= hi){
        ll mid = lo + (hi-lo)/2;
        if(f(mid) <= (2*time)/rank){
            ans = mid;
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }
    return ans;
}

bool possible(ll p, ll time, std::vector<ll> &rank){
    // here we need to find the max pratas that ith cook can make; and sum of all i >= p or not.
    // let k is the number of pratas that ith cook can make:
    // the equation becomes: k^2 + k <= 2*time/rank[i]; rank[i] -> rank of ith cook
    ll sum_p = 0;
    for(int i=0;i<rank.size();i++){
        sum_p += max_pratas(rank[i], time);
    }
    return sum_p >= p;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--){
        ll p;
        std::cin>>p;
        ll l;
        std::cin>>l;
        std::vector<ll> li(l);
        for(ll i=0;i<l;i++) std::cin>>li[i];
        ll lo = 0, hi = ((p*(p+1))/2)*(*std::max_element(li.begin(), li.end())), ans = -1;
        // find the minimum time required to make p pratas.
        while(lo <= hi){
            ll mid = lo + (hi-lo)/2;
            if(possible(p, mid, li)){
                ans = mid;
                hi = mid-1;
            } else {
                lo = mid+1;
            }
        }
        std::cout<<ans<<"\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
