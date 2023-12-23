// https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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

std::vector<ll> dp1, dp2, dp3;
ll happiness(int i, int activity, ll n, std::vector<ll> &a, std::vector<ll> &b, std::vector<ll> &c){
    if(i >= n){
        return 0;
    }

    if(dp1[i] != -1 and activity == 1){
        return dp1[i];
    }
    if(dp2[i] != -1 and activity == 2){
        return dp2[i];
    }
    if(dp3[i] != -1 and activity == 3){
        return dp3[i];
    }

    if(activity == 1){
        dp1[i] = a[i] + (ll)std::max(happiness(i+1, 2, n, a, b, c), happiness(i+1, 3, n, a, b, c));
    }
    if(activity == 2){
        dp2[i] = b[i] + (ll)std::max(happiness(i+1, 1, n, a, b, c), happiness(i+1, 3, n, a, b, c));
    }
    if(activity == 3){
        dp3[i] = c[i] + (ll)std::max(happiness(i+1, 1, n, a, b, c), happiness(i+1, 2, n, a, b, c));
    }

    return std::max({dp1[i], dp2[i], dp3[i]});
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll n;
    std::cin>>n;
    std::vector<ll> a(n), b(n), c(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i]>>b[i]>>c[i];
    }
    dp1.resize(n, -1);
    dp2.resize(n, -1);
    dp3.resize(n, -1);

    dp1[n-1] = a[n-1];
    dp2[n-1] = b[n-1];
    dp3[n-1] = c[n-1];

    for(int i=n-2;i>=0;i--){
        dp1[i] = a[i] + (ll)std::max(dp2[i+1], dp3[i+1]);
        dp2[i] = b[i] + (ll)std::max(dp1[i+1], dp3[i+1]);
        dp3[i] = c[i] + (ll)std::max(dp1[i+1], dp2[i+1]);
    }

    ll ans = std::max({dp1[0], dp2[0], dp3[0]});

    // ll ans = (ll)std::max({happiness(0, 1, n, a, b, c), happiness(0, 2, n, a, b, c), happiness(0, 3, n, a, b, c)});
    std::cout<<ans<<"\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}