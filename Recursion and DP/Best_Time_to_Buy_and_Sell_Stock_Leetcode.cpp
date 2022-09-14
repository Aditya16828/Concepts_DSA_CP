// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

class Solution {
    std::vector<std::vector<int>> dp;
    int helper(int i, int b, std::vector<int> &prices){
        if(i == prices.size()) return 0;

        if(dp[i][b] != -1) return dp[i][b];

        // not pick
        int np = helper(i+1, b, prices);

        // pick
        int p = 0;
        if(b == 1){
            p = helper(i+1, 2, prices) + prices[i];
        } else if(b == 0) {
            p = helper(i+1, 1, prices) - prices[i];
        }
        return dp[i][b] = std::max(np, p);
    }
public:
    int maxProfit(std::vector<int>& prices) {
        dp.resize(prices.size()+1, std::vector<int>(3, -1));
        return helper(0, 0, prices);
    }
};

void file_i_o() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    std::vector<int> prices {7,1,5,3,6,4};
    Solution s;
    std::cout<<(s.maxProfit(prices));

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
