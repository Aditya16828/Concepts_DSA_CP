#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
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

struct Node {
	int val;
	Node* left; // 0
	Node* right; // 1

	Node(int val) {
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

class Binary_Tries {
	Node* root;
public:
	Binary_Tries() {
		root = new Node(-1);
	}

	void insert(int n) {
		Node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (n >> i) & 1;
			if (bit == 1) {
				if (temp->right) {
					temp = temp->right;
				} else {
					Node* new_node = new Node(bit);
					temp->right = new_node;
					temp = new_node;
				}
			}
			if (bit == 0) {
				if (temp->left) {
					temp = temp->left;
				} else {
					Node* new_node = new Node(bit);
					temp->left = new_node;
					temp = new_node;
				}
			}
		}
	}

	ll solve(vll &arr) {
		int n = arr.size();
		insert(arr[0]);
		ll ans = -inf;
		loop(i, 1, n - 1) {
			Node* temp = root;
			ll xor_val = 0;
			rloop(j, 31, 0) {
				int bit = (arr[i] >> j) & 1;
				if (bit == 0) {
					if (temp->right) { // got 1
						temp = temp->right;
						xor_val += pow(2, j);
					} else {
						temp = temp->left;
					}
				}
				if (bit == 1) {
					if (temp->left) { // got 0
						temp = temp->left;
						xor_val += pow(2, j);
					} else {
						temp = temp->right;
					}
				}
			}
			insert(arr[i]);
			ans = std::max(ans, xor_val);
		}
		return ans;
	}
};


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Binary_Tries tr;
	int n;
	std::cin >> n;
	vll arr(n);
	loop(i, 0, n - 1) {
		std::cin >> arr[i];
	}
	std::cout << tr.solve(arr) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
