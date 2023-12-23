#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

// using vector it would be better bcz use of strings would increase the time complexity as copying of strings and creation of new strings are involved
std::vector<std::vector<char>> ans;
void subseq(int i, std::string &s, std::vector<char>&res) {
	if (i == s.length()) {
		ans.push_back(res);
		return;
	}
	res.push_back(s[i]);
	subseq(i + 1, s, res);
	res.pop_back();
	subseq(i + 1, s, res);
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

	std::string str;
	std::cin >> str;
	ans.reserve(1 << (str.size()));
	std::vector<char> res_str;
	subseq(0, str, res_str);
	for (auto &i : ans) {
		for (auto &j : i) std::cout << j;
		std::cout << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}