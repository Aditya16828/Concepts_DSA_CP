<<<<<<< HEAD
// https://www.codechef.com/INOIPRAC/problems/INOI1301
#include <bits/stdc++.h>
#define ll long long int
#define mod 100000000007
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

std::vector<ll> forward, backward;

ll compute_forward(int start, int dest, std::vector<ll> &scores) {
	if (dest == start) return 0;
	if (dest < start) return -1000;
	if (forward[dest] != mod) return forward[dest];
	return forward[dest] = std::max(compute_forward(start, dest - 1, scores), compute_forward(start, dest - 2, scores)) + scores[dest];
}

ll compute_backward(int start, int dest, std::vector<ll> &scores) {
	if (dest == start) return 0;
	if (dest < start) return -1000;
	if (backward[dest] != mod) return backward[dest];
	return backward[dest] = std::max(compute_backward(start, dest - 1, scores), compute_backward(start, dest - 2, scores)) + scores[dest];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, k;
	std::cin >> n >> k;
	std::vector<ll> scores(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> scores[i];
	ll ans = INT_MIN;
// 	k--;
	forward.resize(n + 1, mod);
	backward.resize(n + 1, mod);
	forward[k] = 0;
	forward[k + 1] = scores[k + 1];
	for (int i = k + 2; i <= n; i++) {
		forward[i] = std::max(forward[i - 1], forward[i - 2]) + scores[i];
	}
	backward[1] = scores[1];
	backward[2] = scores[1] + scores[2];
	for (int i = 3; i <= n; i++) {
		backward[i] = std::max(backward[i - 1], backward[i - 2]) + scores[i];
	}
	for (int i = k; i <= n; i++) {
		ans = std::max(ans, forward[i] + backward[i] - scores[i]);
	}
// 	for (int i = k; i <= n; i++) {
// 		ans = std::max(ans, compute_forward(k, i, scores) + compute_backward(1, i, scores) - scores[i]);
// 	}
// 	std::cout << ans + scores[1] << "\n";
	std::cout << ans << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://www.codechef.com/INOIPRAC/problems/INOI1301
#include <bits/stdc++.h>
#define ll long long int
#define mod 100000000007
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

std::vector<ll> forward, backward;

ll compute_forward(int start, int dest, std::vector<ll> &scores) {
	if (dest == start) return 0;
	if (dest < start) return -1000;
	if (forward[dest] != mod) return forward[dest];
	return forward[dest] = std::max(compute_forward(start, dest - 1, scores), compute_forward(start, dest - 2, scores)) + scores[dest];
}

ll compute_backward(int start, int dest, std::vector<ll> &scores) {
	if (dest == start) return 0;
	if (dest < start) return -1000;
	if (backward[dest] != mod) return backward[dest];
	return backward[dest] = std::max(compute_backward(start, dest - 1, scores), compute_backward(start, dest - 2, scores)) + scores[dest];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, k;
	std::cin >> n >> k;
	std::vector<ll> scores(n + 1);
	for (int i = 1; i <= n; i++)
		std::cin >> scores[i];
	ll ans = INT_MIN;
// 	k--;
	forward.resize(n + 1, mod);
	backward.resize(n + 1, mod);
	forward[k] = 0;
	forward[k + 1] = scores[k + 1];
	for (int i = k + 2; i <= n; i++) {
		forward[i] = std::max(forward[i - 1], forward[i - 2]) + scores[i];
	}
	backward[1] = scores[1];
	backward[2] = scores[1] + scores[2];
	for (int i = 3; i <= n; i++) {
		backward[i] = std::max(backward[i - 1], backward[i - 2]) + scores[i];
	}
	for (int i = k; i <= n; i++) {
		ans = std::max(ans, forward[i] + backward[i] - scores[i]);
	}
// 	for (int i = k; i <= n; i++) {
// 		ans = std::max(ans, compute_forward(k, i, scores) + compute_backward(1, i, scores) - scores[i]);
// 	}
// 	std::cout << ans + scores[1] << "\n";
	std::cout << ans << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
