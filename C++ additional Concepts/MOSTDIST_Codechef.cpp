<<<<<<< HEAD
// https://www.codechef.com/problems/MOSTDIST
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

ll A(ll x, ll y){return (x+y);}
ll B(ll x, ll y){return (x-y);}
ll C(ll x, ll y){return (-x+y);}
ll D(ll x, ll y){return (-x-y);}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll q;
    std::cin>>q;
    ll i=1;
    std::vector<bool> removed(500005, false);
    ll answer = 0;
    std::priority_queue<std::pair<ll, ll>> a, b, c, d;
    while(q--){
        // log(q);
        char ch;
        std::cin>>ch;
        if(ch == '+'){
            ll x, y;
            std::cin>>x>>y;
            x=x^answer;
            y=y^answer;
            // log(ch, x, y, i);
            a.push({A(x, y), i});
            b.push({B(x, y), i});
            c.push({C(x, y), i});
            d.push({D(x, y), i});
            ++i;
            // log(a.size());
        } else if (ch == '-'){
            ll n;
            std::cin>>n;
            n=n^answer;
            // log(ch, n);
            removed.at(n)=true;
        } else {
            ll x, y;
            std::cin>>x>>y;
            x=x^answer;
            y=y^answer;
            // log(x, y);
            
            while(not a.empty() and removed.at(a.top().second)) a.pop();
            while(not b.empty() and removed.at(b.top().second)) b.pop();
            while(not c.empty() and removed.at(c.top().second)) c.pop();
            while(not d.empty() and removed.at(d.top().second)) d.pop();

            ll res=INT_MIN;
            if(not a.empty()){
                res = std::max(res, a.top().first - A(x, y));
            }
            if(not b.empty()){
                res = std::max(res, b.top().first - B(x, y));
            }
            if(not c.empty()){
                res = std::max(res, c.top().first - C(x, y));
            }
            if(not d.empty()){
                res = std::max(res, d.top().first - D(x, y));
            }

            if(res > INT_MIN) answer = res;
            std::cout<<res<<"\n";
        }
        // std::cout<<"***********\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
=======
// https://www.codechef.com/problems/MOSTDIST
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

ll A(ll x, ll y){return (x+y);}
ll B(ll x, ll y){return (x-y);}
ll C(ll x, ll y){return (-x+y);}
ll D(ll x, ll y){return (-x-y);}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll q;
    std::cin>>q;
    ll i=1;
    std::vector<bool> removed(500005, false);
    ll answer = 0;
    std::priority_queue<std::pair<ll, ll>> a, b, c, d;
    while(q--){
        // log(q);
        char ch;
        std::cin>>ch;
        if(ch == '+'){
            ll x, y;
            std::cin>>x>>y;
            x=x^answer;
            y=y^answer;
            // log(ch, x, y, i);
            a.push({A(x, y), i});
            b.push({B(x, y), i});
            c.push({C(x, y), i});
            d.push({D(x, y), i});
            ++i;
            // log(a.size());
        } else if (ch == '-'){
            ll n;
            std::cin>>n;
            n=n^answer;
            // log(ch, n);
            removed.at(n)=true;
        } else {
            ll x, y;
            std::cin>>x>>y;
            x=x^answer;
            y=y^answer;
            // log(x, y);
            
            while(not a.empty() and removed.at(a.top().second)) a.pop();
            while(not b.empty() and removed.at(b.top().second)) b.pop();
            while(not c.empty() and removed.at(c.top().second)) c.pop();
            while(not d.empty() and removed.at(d.top().second)) d.pop();

            ll res=INT_MIN;
            if(not a.empty()){
                res = std::max(res, a.top().first - A(x, y));
            }
            if(not b.empty()){
                res = std::max(res, b.top().first - B(x, y));
            }
            if(not c.empty()){
                res = std::max(res, c.top().first - C(x, y));
            }
            if(not d.empty()){
                res = std::max(res, d.top().first - D(x, y));
            }

            if(res > INT_MIN) answer = res;
            std::cout<<res<<"\n";
        }
        // std::cout<<"***********\n";
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
