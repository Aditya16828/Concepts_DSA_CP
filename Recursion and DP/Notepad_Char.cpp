<<<<<<< HEAD
/*
You have a notepad software with only one character 'p' displayed on it.
You can perform 2 ops,
	op1 -> copy all chars on screen
	op2 -> paste paste whatever you copied last time.
Given a value n return min ops to get exactly n 'p's on the screen.
*/
// https://leetcode.com/problems/2-keys-keyboard/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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
	std::bitset<1005> isPrime;
	void gen_primes() {
		isPrime.set();
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i < 1005; i++) {
			if (isPrime[i]) {
				for (int j = 2 * i; j < 1005; j += i) {
					isPrime[j] = false;
				}
			}
		}
	}

	int dp[1005];
	int helper(int n) {
		if (n == 1) return 0;
		if (isPrime[n]) return n;
		if (dp[n] != -1) return dp[n];
		int ans;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				ans = helper(n / i) + i;
				break;
			}
		}
		return dp[n] = ans;
	}
	int minSteps(int n) {
		memset(dp, -1, sizeof dp);
		gen_primes();
		return helper(n);
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
/*
You have a notepad software with only one character 'p' displayed on it.
You can perform 2 ops,
	op1 -> copy all chars on screen
	op2 -> paste paste whatever you copied last time.
Given a value n return min ops to get exactly n 'p's on the screen.
*/
// https://leetcode.com/problems/2-keys-keyboard/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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
	std::bitset<1005> isPrime;
	void gen_primes() {
		isPrime.set();
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i < 1005; i++) {
			if (isPrime[i]) {
				for (int j = 2 * i; j < 1005; j += i) {
					isPrime[j] = false;
				}
			}
		}
	}

	int dp[1005];
	int helper(int n) {
		if (n == 1) return 0;
		if (isPrime[n]) return n;
		if (dp[n] != -1) return dp[n];
		int ans;
		for (int i = 2; i < n; i++) {
			if (n % i == 0) {
				ans = helper(n / i) + i;
				break;
			}
		}
		return dp[n] = ans;
	}
	int minSteps(int n) {
		memset(dp, -1, sizeof dp);
		gen_primes();
		return helper(n);
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
