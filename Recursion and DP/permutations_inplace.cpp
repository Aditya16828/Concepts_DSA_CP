#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void permute(std::vector<int> nums, int idx) {
	if (idx == nums.size()) {
		for (auto &ele : nums) {
			std::cout << ele << " ";
		}
		std::cout << "\n";
		return;
	}
	for (int i = idx; i < nums.size(); i++) {
		std::swap(nums[idx], nums[i]);
		permute(nums, idx + 1);
		std::swap(nums[idx], nums[i]);
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
	std::vector<int> a(n);
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	permute(a, 0);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}