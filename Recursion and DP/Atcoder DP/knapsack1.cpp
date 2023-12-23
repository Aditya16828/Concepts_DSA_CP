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

ll maxValue(int idx, ll wt, std::vector<ll> &values, std::vector<ll> &weights, std::vector<std::vector<ll>> &dp){
	if(idx == 0){
		if(weights[0] <= wt) return values[0];
		else return 0;
	}

	if(dp[idx][wt] != -1) return dp[idx][wt];

	ll notpick = maxValue(idx-1, wt, values, weights, dp);
	ll pick = INT_MIN;
	if(wt >= weights[idx]){
		pick = values[idx] + maxValue(idx-1, wt-weights[idx], values, weights, dp);
	}

	return dp[idx][wt] = std::max(pick, notpick);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, w;
	std::cin>>n>>w;
	std::vector<ll> weights(n), values(n);
	for(int i=0;i<n;i++){
		std::cin>>weights[i]>>values[i];
	}
	std::vector<std::vector<ll>> dp(n, std::vector<ll>(w+1, 0));

	// Tabulation
	// step1: Base cases
	for(int wt=weights[0];wt<=w;wt++){
		dp[0][wt] = values[0];
	}

	// run the states loops
	for(int idx=1;idx<n;idx++){
		for(int wt=w;wt>=1;wt--){
			ll notpick = dp[idx-1][wt];
			ll pick = -1e12;
			if(weights[idx] <= wt){
				pick = values[idx] + dp[idx-1][wt-weights[idx]];
			}

			dp[idx][wt] = std::max(pick, notpick);
		}
	}

	// std::cout<<maxValue(n-1, w, values, weights, dp);
	std::cout<<dp[n-1][w];

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}