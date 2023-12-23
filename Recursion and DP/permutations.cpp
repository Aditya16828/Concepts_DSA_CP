<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void print_permutations(std::vector<int> &nums, std::vector<bool> &vis, std::vector<int> &res) {
	if (res.size() == nums.size()) {
		for (auto &i : res)
			std::cout << i << ", ";
		std::cout << "\n";
		return;
	}
	int n = nums.size();
	for (int x = 0; x < n; x++) {
		if (not vis[x]) {
			vis[x] = true;
			res.push_back(nums[x]);
			print_permutations(nums, vis, res);
			vis[x] = false;
			res.pop_back();
		}
	}
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

	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++) std::cin >> nums[i];
	std::vector<bool> visited(n, false);
	std::vector<int> result;
	print_permutations(nums, visited, result);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void print_permutations(std::vector<int> &nums, std::vector<bool> &vis, std::vector<int> &res) {
	if (res.size() == nums.size()) {
		for (auto &i : res)
			std::cout << i << ", ";
		std::cout << "\n";
		return;
	}
	int n = nums.size();
	for (int x = 0; x < n; x++) {
		if (not vis[x]) {
			vis[x] = true;
			res.push_back(nums[x]);
			print_permutations(nums, vis, res);
			vis[x] = false;
			res.pop_back();
		}
	}
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

	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++) std::cin >> nums[i];
	std::vector<bool> visited(n, false);
	std::vector<int> result;
	print_permutations(nums, visited, result);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}