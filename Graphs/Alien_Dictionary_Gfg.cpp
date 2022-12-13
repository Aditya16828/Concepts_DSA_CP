// https://practice.geeksforgeeks.org/problems/alien-dictionary/1/
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

class Solution {
public:
    std::string findOrder(std::vector<std::string>& dict, int N, int K) {
        std::vector<int> indegree(K, 0);
        std::vector<std::set<char>> g(K, std::set<char>());

        for (int i = 0;i < N - 1;i++) {
            std::string curr = dict[i];
            std::string next = dict[i + 1];

            int sz = std::min(curr.size(), next.size());

            for (int j = 0;j < sz;j++) {
                if (curr[j] != next[j]) {
                    if (g[curr[j] - 'a'].count(next[j]) == 0) {
                        g[curr[j] - 'a'].insert(next[j]);
                        indegree[next[j] - 'a']++;
                    }
                    break;
                }
            }
        }

        // loop(i, 0, K - 1) {
        //     std::cout << (char)(i + 'a') << "->";
        //     iter_all(x, g[i]) {
        //         std::cout << x << ", ";
        //     }
        //     std::cout << "\n";
        // }

        // loop(i, 0, K - 1) {
        //     std::cout << (char)(i + 'a') << "->" << indegree[i] << "\n";
        // }

        std::string ans = "";

        std::queue<int> q;
        for (int i = 0;i < K;i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (not q.empty()) {
            int idx = q.front();
            ans += (char)(idx + 'a');
            q.pop();
            for (auto& ne : g[idx]) {
                indegree[ne - 'a']--;
                if (indegree[ne - 'a'] == 0) {
                    q.push(ne - 'a');
                }
            }
        }

        return ans;
    }
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    std::vector<std::string> d{ "caa","aaa","aab" };
    int n = d.size();
    int k = 3;
    Solution s;
    std::cout << s.findOrder(d, n, k) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
