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

void upheapify(std::vector<int> &heap, int cidx){
	if(cidx == 0)
		return;
	int pidx = (cidx-1)/2;
	if(heap[pidx] < heap[cidx]){
		std::swap(heap[pidx], heap[cidx]);
		upheapify(heap, pidx);
	}
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

void insert(std::vector<int> &heap, int key){
	heap.push_back(key);
	upheapify(heap, heap.size()-1);
}

int get(std::vector<int> &heap){
	return heap[0];
}

void remove(std::vector<int> &heap, int idx){
	if(idx >= heap.size()) return;

	heap[idx] = INT_MAX;
	upheapify(heap, idx);

	std::swap(heap[0], heap[heap.size()-1]);

	heap.pop_back();
	downheapify(heap, 0);
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
	std::vector<int> heap;
	while (n--){
		int x;
		std::cin>>x;
		insert(heap, x);
	}
	
	print(heap);

	remove(heap, 3);

	print(heap);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}