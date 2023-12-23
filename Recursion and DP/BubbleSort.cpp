<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<int> v;
void bubble_sort(int i, int n) {
    if (n == 1) return;
    if (i == n - 1) {
        for (auto &ele : v) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
        bubble_sort(0, n - 1);
        return;
    }
    if (v[i] > v[i + 1])
        std::swap(v[i + 1], v[i]);
    bubble_sort(i + 1, n);
    return;
}

int main()
{
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
    bubble_sort(0, n);
    //for (auto &i : v) std::cout << i << " ";


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<int> v;
void bubble_sort(int i, int n) {
    if (n == 1) return;
    if (i == n - 1) {
        for (auto &ele : v) {
            std::cout << ele << " ";
        }
        std::cout << "\n";
        bubble_sort(0, n - 1);
        return;
    }
    if (v[i] > v[i + 1])
        std::swap(v[i + 1], v[i]);
    bubble_sort(i + 1, n);
    return;
}

int main()
{
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
    bubble_sort(0, n);
    //for (auto &i : v) std::cout << i << " ";


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}