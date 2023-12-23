<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)
#define MAX (int)(1e6+5)

using namespace std;

vector<ll> pi(MAX);

void gen_pi() {
	for (int i = 0; i < MAX; i++) pi[i] = i;
	for (int i = 2; i < MAX; i++) {
		if (pi[i] == i) pi[i] = i - 1;
		for (int j = 2 * i; j < MAX; j += i) {
			pi[j] = (pi[j] * (i - 1)) / i;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	gen_pi();

	int n;
	cin >> n;
	cout << pi[n];

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)
#define MAX (int)(1e6+5)

using namespace std;

vector<ll> pi(MAX);

void gen_pi() {
	for (int i = 0; i < MAX; i++) pi[i] = i;
	for (int i = 2; i < MAX; i++) {
		if (pi[i] == i) pi[i] = i - 1;
		for (int j = 2 * i; j < MAX; j += i) {
			pi[j] = (pi[j] * (i - 1)) / i;
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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	gen_pi();

	int n;
	cin >> n;
	cout << pi[n];

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}