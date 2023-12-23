#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
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

std::vector<int> merge(std::vector<int>& arr1, std::vector<int>& arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    int gap = ceil((n1 + n2) / 2.0);

    std::vector<int> arr(n1 + n2, 0);
    loop(i, 0, n1 - 1) arr[i] = arr1[i];
    loop(i, 0, n2 - 1) arr[n1 + i] = arr2[i];

    // logarr(arr, 0, arr.size()-1);

    while (gap) {
        int p1 = 0;
        int p2 = (p1 + gap);

        while (p2 < arr.size()) {
            if (arr[p1] > arr[p2]) {
                std::swap(arr[p1], arr[p2]);
            }
            ++p1;
            ++p2;
        }

        if (gap > 1 and gap % 2 == 1) {
            gap = gap / 2 + 1;
        } else {
            gap = gap / 2;
        }
    }

    return arr;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> arr1(n1), arr2(n2);

    for (int i = 0;i < n1;i++) {
        std::cin >> arr1[i];
    }
    for (int i = 0;i < n2;i++) {
        std::cin >> arr2[i];
    }

    std::vector<int> arr = merge(arr1, arr2);

    logarr(arr, 0, arr.size() - 1);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}