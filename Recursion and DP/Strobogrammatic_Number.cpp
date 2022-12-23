// https://www.lintcode.com/problem/644/
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

bool helper(std::string s) {
	if (s == "1" or s == "8" or s == "0") return true;
	if (s == "") return true;
	char f = s[0], l = s[s.length() - 1];
	bool temp = helper(s.substr(1, s.length() - 2));
	return temp and ((f == '0' and l == '0') or (f == '1' and l == '1') or (f == '8' and l == '8') or (f == '6' and l == '9') or (f == '9' and l == '6'));
}

bool isStrobogrammatic(std::string &num) {
	return helper(num);
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
	std::cout << (isStrobogrammatic(str) ? "Yes" : "No");

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}