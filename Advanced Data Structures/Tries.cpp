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
	char ch;
	bool isEnd;
	std::unordered_map<char, Node*> child;

	Node(char ch) {
		this->ch = ch;
		isEnd = false;
	}
};

class Trie {
	Node* root;
public:
	Trie() {
		this->root = new Node('\0');
	}

	void insert(std::string s) {
		Node* temp = root;
		int n = s.size();
		loop(i, 0, n - 1) {
			char ch = s[i];
			if (temp->child.count(ch)) {
				temp = temp->child[ch];
			} else {
				Node* node = new Node(ch);
				temp->child[ch] = node;
				temp = node;
			}
		}
		temp->isEnd = true;
		return;
	}

	bool search(std::string str) {
		int n = str.size();
		Node* temp = root;
		loop(i, 0, n - 1) {
			char ch = str[i];
			if (temp->child[ch]) {
				temp = temp->child[ch];
			} else {
				if (temp->isEnd) {
					return true;
				} else return false;
			}
		}
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
