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

class Max_Heap {
	std::vector<int> heap;

	void upheapify(int idx) {
		if (idx == 0) return;

		int p_idx = (idx - 1) / 2;

		if (heap[p_idx] > heap[idx]) return;
		else {
			std::swap(heap[p_idx], heap[idx]);
			upheapify(p_idx);
			return;
		}
	}

	void downheapify(int idx) {
		int lc_idx = 2 * idx + 1;
		int rc_idx = 2 * idx + 2;

		if (lc_idx >= heap.size() and rc_idx >= heap.size()) return;

		int max_idx = idx;

		if (lc_idx < heap.size() and heap[lc_idx] > heap[max_idx]) max_idx = lc_idx;
		if (rc_idx < heap.size() and heap[rc_idx] > heap[max_idx]) max_idx = rc_idx;

		if (max_idx == idx) return;
		else {
			std::swap(heap[max_idx], heap[idx]);
			downheapify(max_idx);
			return;
		}
	}

public:
	Max_Heap(std::vector<int> &arr) {
		heap = arr;
		int n = arr.size();
		loop(i, 0, n - 1) {
			downheapify(i);
		}
	}

	bool isempty() {
		return (heap.size() <= 0);
	}

	void push(int el) {
		heap.push_back(el);
		upheapify(heap.size() - 1);
	}

	void pop() {
		std::swap(heap[0], heap[heap.size() - 1]);
		heap.pop_back();
		downheapify(0);
	}

	int top() {
		if (isempty()) {
			std::cout << "Empty Heap\n";
			return INT_MAX;
		}
		return heap[0];
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	loop(i, 0, n - 1) {
		std::cin >> arr[i];
	}
	Max_Heap heap(arr);

	// print heap
	while (not heap.isempty()) {
		std::cout << heap.top() << ", ";
		heap.pop();
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}