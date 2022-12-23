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
	std::vector<std::string> res;
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
				return false;
			}
		}
		return temp->isEnd;
	}

	void dfs(Node* node, std::string& pre, std::string out) {
		if (node == NULL) return;
		if (node->isEnd) {
			res.push_back(pre + out);
		}
		iter_all(c, node->child) {
			dfs(c.second, pre,  out + c.first);
		}
	}

	void print_prefix(std::string pre) {
		Node* temp = root;
		int n = pre.size();
		loop(i, 0, n - 1) {
			char ch = pre[i];
			if (temp->child.count(ch)) {
				temp = temp->child[ch];
			} else {
				return;
			}
		}
		dfs(temp, pre, "");
		iter_all(el, res) {
			std::cout << el << ", ";
		}
		std::cout << "\n";
	}

	bool dfs_delete(Node* node, int i, std::string &s) {
		if (node == NULL) return true;

		if (i == s.size() - 1) {
			if (node->isEnd) {
				if (node->child.size() == 0) {
					delete node;
					return true;
				} else {
					node->isEnd = false;
					return false;
				}
			} else return false;
		}

		bool todelete = false;

		if (node->child.count(s[i + 1])) {
			todelete = dfs_delete(node->child[s[i + 1]], i + 1, s);
			if (todelete) node->child.erase(s[i + 1]);
		}
		if (node->child.size() == 0) {
			delete node;
			return true;
		}
		return false;
	}

	void delete_str(std::string s) {
		if (not this->search(s)) {std::cout << "Not present\n"; return;}
		int n = s.size();
		Node* temp = root;
		dfs_delete(temp->child[s[0]], 0, s);
		std::cout << "Deleted\n";
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	Trie tr;
	while (t--) {
		std::string s;
		std::cin >> s;
		tr.insert(s);
	}

	// int q;
	// std::cin >> q;
	// while (q--) {
	// 	std::string str;
	// 	std::cin >> str;
	// 	std::cout << (tr.search(str) ? "Found" : "Not Found") << "\n";
	// }

	// std::string prefix;
	// std::cin >> prefix;
	// tr.print_prefix(prefix);

	std::string str;
	std::cin >> str;
	tr.delete_str(str);

	std::cout << (tr.search(str) ? "Found" : "Not Found") << "\n";

	std::string prefix;
	std::cin >> prefix;
	tr.print_prefix(prefix);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
