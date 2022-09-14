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
#define print_container(el, cont) for(auto &el:cont)

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

/*
idx -> tree index, will be used to operate on segment
start, end -> range of the segment in each recursive call on the array arr.
*/

void build(vi &arr, vi &seg, int start, int end, int idx) {
    if (start == end) {
        seg[idx] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;

    build(arr, seg, start, mid, 2 * idx + 1);
    build(arr, seg, mid + 1, end, 2 * idx + 2);

    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}


void update(vi &arr, vi &seg, int tidx, int i, int start, int end) {
    if (start == end) {
        seg[tidx] = arr[i];
        return;
    }
    int mid = start + (end - start) / 2;

    if (i > mid) {
        update(arr, seg, 2 * tidx + 2, i, mid + 1, end);
    } else {
        update(arr, seg, 2 * tidx + 1, i, start, mid);
    }
    seg[tidx] = seg[2 * tidx + 1] + seg[2 * tidx + 2];
}

int sum(vi &seg, int tidx, int start, int end, int l, int r) {
    if (end < l or start > r) {
        return 0;
    }
    if (start >= l and end <= r) {
        return seg[tidx];
    }
    int mid = start + (end - start) / 2;

    int x1 = sum(seg, 2 * tidx + 1, start, mid, l, r);
    int x2 = sum(seg, 2 * tidx + 2, mid + 1, end, l, r);

    return x1 + x2;
}


int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin >> n;
    vi arr(n);
    loop(i, 0, n - 1) std::cin >> arr[i];

    std::vector<int> seg(4 * n, 0);
    build(arr, seg, 0, n - 1, 0);

    int q;
    std::cin >> q;
    while (q--) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int i, val;
            std::cin >> i >> val;
            arr[i] = val;
            update(arr, seg, 0, i, 0, n - 1);
        } else {
            int l, r;
            std::cin >> l >> r;
            std::cout << sum(seg, 0, 0, n - 1, l, r) << "\n";
        }
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}

/*
6
3 1 -4 2 8 7
5
2 0 2
1 2 4
2 0 2
2 1 5
2 2 4
*/
