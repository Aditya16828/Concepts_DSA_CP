<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

/*
f(i) -> checks whether an array starting from index i is sorted or not;
f(i) = f(i+1) and (a[i] <= a[i+1])
*/

bool isSorted(std::vector<int> &v, int start_idx) {
	if (start_idx == v.size() - 1) return true;
	else {
		bool temp = isSorted(v, start_idx + 1);
		return temp and (v[start_idx] <= v[start_idx + 1]);
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
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::cout << (isSorted(v, 0) ? "Sorted" : "Not Sorted" ) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

/*
f(i) -> checks whether an array starting from index i is sorted or not;
f(i) = f(i+1) and (a[i] <= a[i+1])
*/

bool isSorted(std::vector<int> &v, int start_idx) {
	if (start_idx == v.size() - 1) return true;
	else {
		bool temp = isSorted(v, start_idx + 1);
		return temp and (v[start_idx] <= v[start_idx + 1]);
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
	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::cout << (isSorted(v, 0) ? "Sorted" : "Not Sorted" ) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}