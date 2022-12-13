// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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

class Solution {
	std::vector<std::string> res;
	std::vector<std::string> mapping {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	void helper(std::string digits, int i, std::string output) {
		if (i == digits.size()) {
			res.push_back(output);
			return;
		}
		for (int j = 0; j < mapping[digits[i] - '0'].size(); j++) {
			helper(digits, i + 1, output + mapping[digits[i] - '0'][j]);
		}
	}
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() <= 0) return {};
		helper(digits, 0, "");
		return res;
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



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
