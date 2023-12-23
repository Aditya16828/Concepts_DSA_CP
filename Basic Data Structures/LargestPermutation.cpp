<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<ll> permute(std::vector<ll> &v, ll k) {
	std::map<ll, ll> reqd_idx;
	std::map<ll, ll> original_idx;
	ll n = v.size();
	for (int i = 0; i < n; i++) {
		original_idx[v[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		reqd_idx[n - i] = i;
	}
	for (auto itr = reqd_idx.rbegin(); itr != reqd_idx.rend(); ++itr) {
		if ((*itr).second == original_idx[(*itr).first]) {continue;}
		else {
			ll oidx = original_idx[(*itr).first];
			ll ridx = (*itr).second;
			ll x = v[ridx];
			ll y = v[oidx];
			std::swap(v[ridx], v[oidx]);
			std::swap(original_idx[x], original_idx[y]);
			k--;
		}
		if (k == 0) break;
	}
	return v;
}

void display(std::vector<ll> &v) {
	for (auto &ele : v) {
		std::cout << ele << " ";
	}
	std::cout << "\n";
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

	ll n, k;
	std::cin >> n >> k;
	std::vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	v = permute(v, k);
	display(v);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<ll> permute(std::vector<ll> &v, ll k) {
	std::map<ll, ll> reqd_idx;
	std::map<ll, ll> original_idx;
	ll n = v.size();
	for (int i = 0; i < n; i++) {
		original_idx[v[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		reqd_idx[n - i] = i;
	}
	for (auto itr = reqd_idx.rbegin(); itr != reqd_idx.rend(); ++itr) {
		if ((*itr).second == original_idx[(*itr).first]) {continue;}
		else {
			ll oidx = original_idx[(*itr).first];
			ll ridx = (*itr).second;
			ll x = v[ridx];
			ll y = v[oidx];
			std::swap(v[ridx], v[oidx]);
			std::swap(original_idx[x], original_idx[y]);
			k--;
		}
		if (k == 0) break;
	}
	return v;
}

void display(std::vector<ll> &v) {
	for (auto &ele : v) {
		std::cout << ele << " ";
	}
	std::cout << "\n";
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

	ll n, k;
	std::cin >> n >> k;
	std::vector<ll> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	v = permute(v, k);
	display(v);


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}