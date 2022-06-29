// https://www.spoj.com/problems/CPCRC1C/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)   { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)  for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

std::vector<ll> tens_power(13, 1);
void compute(){
    //tens_power.push_back(1);
    for(int i=1;i<=12;i++){
        tens_power[i] = tens_power[i-1]*10;
    }
}

// Let n = 8655
ll f(ll n){
    if(n/10 == 0) return (n*(n+1))/2;

    // {
    std::string str = std::to_string(n);
    ll d = str.size();
    int first_num = n/tens_power[d-1];
    ll ans = 0;
    for(int i=0;i<first_num;i++){
        ans += (i * tens_power[d-1]);
        ans += ((45 * tens_power[d-2]) * (d-1));// contributuion of each number (0 to 9) for the hundredth, tenth and oneth place in 7999.
    }
    ans += first_num*(1 + (n % tens_power[d-1])); // contribution of 8 from 8000 to 8655.
    // } -> this whole part represents contribution of each number till 7999

    // Now we need to find the ans for the rest 656 numbers, i.e., from 8000 to 8655
    // out of which we have already calculated the contribution of 8, so only contribution of each numbers in 655 is remaining.
    return (ans + f(n%tens_power[d-1]));
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll a, b;
    std::cin>>a>>b;
    compute();
    while(a > -1 and b > -1){
        std::cout<<(f(b)-f(a-1))<<"\n";
        std::cin>>a>>b;
    }

    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
