// https://www.codechef.com/problems/AMCS03
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

double f(std::vector<int> s, std::vector<int> d, double t){
    //std::vector<double> p;
    double min = LLONG_MAX;
    double max = LLONG_MIN;
    for(int i=0;i<s.size();i++){
        double temp = s[i]*t + d[i];
        min = std::min(min, temp);
        max = std::max(max, temp);
    }
    return (max-min);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, k;
    std::cin>>n>>k;
    std::vector<int> s(n), d(n);
    for(int i=0;i<n;i++) std::cin>>s[i]>>d[i];
    double lo = 0, hi = k, ans = -1;
    for(int _ = 0;_<150;_++){
        double m1 = lo + (hi-lo)/3;
        double m2 = hi - (hi-lo)/3;

        if(f(s, d, m1) < f(s, d, m2)){
            hi = m2;
        } else {
            ans = m1;
            lo = m1;
        }
    }
    std::cout<<std::fixed<<std::setprecision(6)<<f(s, d, ans)<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
