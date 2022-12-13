#include <bits/stdc++.h>
#define ll long long int

std::vector<int> v;
void reverse(int start, int end) {
    if (start >= end) return;
    std::swap(v[start], v[end]);
    reverse(start + 1, end - 1);
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

    int n;
    std::cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    reverse(0, n - 1);
    for (auto &x : v) std::cout << x << " ";
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
