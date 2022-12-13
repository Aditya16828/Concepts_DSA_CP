#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

int k;
vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	vector<vector<ll>> res(k, vector<ll>(k, 0));
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			for (int x = 0; x < k; x++) {
				res[i][j] = (res[i][j] + (a[i][x] * b[x][j]) % mod) % mod;
			}
		}
	}
	return res;
}

vector<vector<ll>> pow(vector<vector<ll>> &mat, ll exp) {
	vector<vector<ll>> res {{1, 0}, {0, 1}};
	while (exp) {
		if (exp % 2 != 0) res = multiply(res, mat);
		mat = multiply(mat, mat);
		exp = exp / 2;
	}
	return res;
}

ll fibo(ll n) {
	vector<vector<ll>> transformation_mat = {{0, 1}, {1, 1}};
	if (n == 0) return 0;
	transformation_mat = pow(transformation_mat, n - 1);
	ll fibo1[2] = {0, 1};
	return (((transformation_mat[1][0] * fibo1[0]) % mod) + ((transformation_mat[1][1] * fibo1[1]) % mod)) % mod;
}

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	k = 2;
	ll n;
	cin >> n;
	cout << fibo(n) << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}