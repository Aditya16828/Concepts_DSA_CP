// https://codeforces.com/contest/1350/problem/C
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

int const max_size = (int)(2e5) + 2;
vi pi(max_size, 0);
vi primes;
void gen_primes() {
    loop(i, 0, max_size - 1) {
        pi[i] = i;
    }
    pi[0] = pi[1] = -1;

    loop(i, 2, max_size - 1) {
        if (pi[i] == i) {
            primes.push_back(i);
        }
        for (ll j = 0; (i < primes.size()) and (i * primes[j] < max_size) and (primes[j] <= pi[i]); j++) {
            pi[primes[j] * i] = primes[j];
        }
    }
}

ll mod_exp(ll base, ll pow) {
    ll res = 1;
    while (pow) {
        if (pow % 2) {
            res = (res * base);
        }
        base = (base * base);
        pow /= 2;
    }
    return res;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    gen_primes();
    int n;
    std::cin >> n;
    std::map<int, std::vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
        int power = 0, prev_prime = pi[temp];
        while (temp > 1) {
            if (prev_prime != pi[temp]) {
                mp[prev_prime].push_back(power);
                power = 0;
            }
            prev_prime = pi[temp];
            temp = temp / pi[temp];
            ++power;
        }
        mp[prev_prime].push_back(power);
    }
    ll ans = 1;
    for (auto &x : mp) {
        int s = x.second.size();
        if (s == n or s == n - 1) {
            std::sort(x.second.begin(), x.second.end());
            if (s == n) ans *= pow_bin(x.first, x.second[1]);
            else ans *= pow_bin(x.first, x.second[0]);
        }
    }
    std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
