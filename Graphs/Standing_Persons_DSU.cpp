/*
n persons standing in a row at positions 1 to n, we can do 2 ops"
    1. - x => remove the per son at position x
    2. ? x => find the nearest person to the right x (including x) that is not removed.
There will be q queries.
 q <= 1e6
*/
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

ll Get(vi& leader, int a) {
    return leader[a] = (leader[a] == a) ? a : Get(leader, leader[a]);
}

void Union(vi& leader, int a, int b) {
    a = Get(leader, a);
    b = Get(leader, b);
    leader[a] = b;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin >> n;
    vi leader(n + 1);
    loop(i, 0, n) {
        leader[i] = i;
    }
    int q;
    std::cin >> q;
    while (q--) {
        char ch;
        int x;
        std::cin >> ch >> x;
        if (ch == '-') {
            Union(leader, x, x + 1);
        } else {
            std::cout << Get(leader, x) << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
