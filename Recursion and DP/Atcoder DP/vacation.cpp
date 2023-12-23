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

std::vector<std::vector<int>> dp;

int maxPoints(int last_task, int day, std::vector<std::vector<int>> &task, int &days){
	if(day == days){
		return 0;
	}

	if(dp[last_task][day] != -1) return dp[last_task][day];

	int maxi = 0;

	for(int i=0;i<3;i++){
		if(i == last_task) continue;
		maxi = std::max(maxi, maxPoints(i, day+1, task, days) + task[i][day]);
	}

	return dp[last_task][day] = maxi;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin>>n;
	std::vector<std::vector<int>> task(3, std::vector<int>(n));

	dp.resize(4, std::vector<int>(n, -1));
	
	for(int i=0;i<n;i++){
		std::cin>>task[0][i]>>task[1][i]>>task[2][i];
	}
	
	// std::cout<<maxPoints(0, 3, task, n);

	dp[0][0] = std::max(task[1][0], task[2][0]);
	dp[1][0] = std::max(task[0][0], task[2][0]);
	dp[2][0] = std::max(task[0][0], task[1][0]);
	dp[3][0] = std::max({task[0][0], task[1][0], task[2][0]});

	for(int day = 1;day < n;day++){
		for(int last_task = 0;last_task<4;last_task++){
			dp[last_task][day] = -1;

			int maxi = 0;
			for(int i=0;i<3;i++){
				if(i == last_task) continue;
				maxi = std::max(maxi, dp[i][day-1] + task[i][day]);
			}

			dp[last_task][day] = maxi;
		}
	}

	std::cout<<dp[3][n-1];

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}