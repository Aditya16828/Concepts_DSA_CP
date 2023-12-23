<<<<<<< HEAD
// https://codeforces.com/problemset/problem/1295/D
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

ll phi(ll n) {
    ll ans = n;
    for (ll i = 2; i * i <= n; ++i) {
        ll alpha = 0;
        while ((n % i) == 0) {
            n /= i;
            ++alpha;
        }
        if (alpha) {
            ans /= i;
            ans *= (i - 1);
        }
    }
    // if n is a prime in itself
    if (n > 1) {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

int main() {
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        ll a, m;
        std::cin >> a >> m;
        std::cout << phi(m / std::__gcd(a, m)) << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
=======
// https://codeforces.com/problemset/problem/1295/D
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

ll phi(ll n) {
    ll ans = n;
    for (ll i = 2; i * i <= n; ++i) {
        ll alpha = 0;
        while ((n % i) == 0) {
            n /= i;
            ++alpha;
        }
        if (alpha) {
            ans /= i;
            ans *= (i - 1);
        }
    }
    // if n is a prime in itself
    if (n > 1) {
        ans /= n;
        ans *= (n - 1);
    }
    return ans;
}

int main() {
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        ll a, m;
        std::cin >> a >> m;
        std::cout << phi(m / std::__gcd(a, m)) << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}