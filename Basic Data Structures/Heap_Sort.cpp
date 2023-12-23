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

void downheapify(std::vector<int> &heap, int pidx, int &hs){
	int lcidx = 2*pidx+1;
	int rcidx = 2*pidx+2;

	if(lcidx >= hs and rcidx >= hs) return;

	int max_idx = pidx;

	if(lcidx < hs and heap[max_idx] < heap[lcidx]){
		max_idx = lcidx;
	}
	if(rcidx < hs and heap[max_idx] < heap[rcidx]){
		max_idx = rcidx;
	}

	if(pidx == max_idx) return;

	std::swap(heap[max_idx], heap[pidx]);
	downheapify(heap, max_idx, hs);
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
		downheapify(arr, idx, n);
		idx--;
	}

	// sorting
	int size = n;
	while(size){
		std::swap(arr[0], arr[size-1]);
		size--;
		downheapify(arr, 0, size);
	}

	logarr(arr, 0, arr.size()-1);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}