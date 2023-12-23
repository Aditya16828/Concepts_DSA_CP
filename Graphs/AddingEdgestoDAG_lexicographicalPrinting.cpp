// https://www.codechef.com/problems/RRDAG
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

std::vector<std::vector<int>> gt;

bool cmp(int a, int b) {
    return a > b;
}

std::vector<int> modified_topo_sort(int n) {
    std::vector<int> indegree(n, 0);

    loop(i, 0, n - 1) {
        for (auto& el : gt[i]) {
            indegree[el]++;
        }
    }

    std::priority_queue<int> pq;

    loop(i, 0, n - 1) {
        if (indegree[i] == 0)
            pq.push(i);
    }

    std::vector<bool> vis(n, 0);

    std::vector<int> res;

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();

        if (vis[curr]) continue;

        vis[curr] = true;
        res.push_back(curr);
        for (auto& ne : gt[curr]) {
            indegree[ne]--;
            if (indegree[ne] == 0) {
                pq.push(ne);
            }
        }
    }

    return res;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin >> n;

    gt.resize(n, std::vector<int>());
    std::vector<std::string> mat;

    loop(i, 0, n - 1) {
        std::string temp;
        std::cin >> temp;
        mat.push_back(temp);
        loop(j, 0, n - 1) {
            if (temp[j] - '0') {
                gt[j].push_back(i);
            }
        }
    }

    std::vector<int> res = modified_topo_sort(n);
    std::vector<std::vector<bool>> res_g(n, std::vector<bool>(n, 0));
    loop(i, 0, n - 1) {
        loop(j, i, n - 1) {
            if (i == j) continue;
            else {
                res_g[res[j]][res[i]] = 1;
            }
        }
    }
    std::vector<std::pair<int, int>> ans;
    loop(i, 0, n - 1) {
        loop(j, 0, n - 1) {
            if (mat[i][j] - '0') continue;
            if (res_g[i][j]) {
                ans.push_back({ i, j });
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (int i = 0;i < ans.size();i++) {
        std::cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}