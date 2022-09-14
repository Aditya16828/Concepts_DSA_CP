// https://www.codechef.com/problems/ICM2003
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

double f(double x, double b, double c){
    return (((x*x) + (b*x) + c)/sin(x));
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while (t--) {
        double b, c;
        std::cin>>b>>c;
        double lo = 0, hi = 1.57079632679, ans = -1;
        for(int _=0;_<150;_++){
            double m1 = lo + (hi-lo)/3;
            double m2 = hi - (hi-lo)/3;

            if(f(m1, b, c) < f(m2, b, c)){
                hi = m2;
            } else {
                ans = m1;
                lo = m1;
            }
        }
        std::cout<<std::fixed<<std::setprecision(9)<<f(ans, b, c)<<"\n";
    }
    

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
