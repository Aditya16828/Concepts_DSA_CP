<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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

void downheapify(std::vector<int> &heap, int pidx){
	int lcidx = 2*pidx + 1;
	int rcidx = 2*pidx + 2;

	int max_idx = pidx;
	if(heap.size() <= lcidx and heap.size() <= rcidx) return;

	if(lcidx < heap.size() and heap[lcidx] > heap[max_idx]){
		max_idx = lcidx;
	} else if (rcidx < heap.size() and heap[rcidx] > heap[max_idx]) {
		max_idx = rcidx;
	}

	if(max_idx == pidx) return;

	std::swap(heap[pidx], heap[max_idx]);
	downheapify(heap, max_idx);
}

void print(std::vector<int> &heap){
	for(auto &el:heap)
		std::cout<<el<<", ";
	std::cout<<"\n";
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin>>n;
	std::vector<int> arr(n);
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}

	int idx = (n/2)+1;
	while(idx >= 0){
		downheapify(arr, idx);
		idx--;
	}

	print(arr);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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

void downheapify(std::vector<int> &heap, int pidx){
	int lcidx = 2*pidx + 1;
	int rcidx = 2*pidx + 2;

	int max_idx = pidx;
	if(heap.size() <= lcidx and heap.size() <= rcidx) return;

	if(lcidx < heap.size() and heap[lcidx] > heap[max_idx]){
		max_idx = lcidx;
	} else if (rcidx < heap.size() and heap[rcidx] > heap[max_idx]) {
		max_idx = rcidx;
	}

	if(max_idx == pidx) return;

	std::swap(heap[pidx], heap[max_idx]);
	downheapify(heap, max_idx);
}

void print(std::vector<int> &heap){
	for(auto &el:heap)
		std::cout<<el<<", ";
	std::cout<<"\n";
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin>>n;
	std::vector<int> arr(n);
	for(int i=0;i<n;i++){
		std::cin>>arr[i];
	}

	int idx = (n/2)+1;
	while(idx >= 0){
		downheapify(arr, idx);
		idx--;
	}

	print(arr);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}