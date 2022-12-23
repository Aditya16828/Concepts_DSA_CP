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
	int count;
	std::unordered_map<char, Node*> childs;
	bool isEnd;

	Node(char ch) {
		this->ch = ch;
		this->count = 1;
		this->isEnd = false;
	}
};

class Trie {
	Node* root;
	std::vector<std::vector<char>> prefix;
public:
	Trie() {
		root = new Node('\0');
	}

	void insert(std::string s) {
		int n = s.size();
		Node* temp = this->root;
		loop(i, 0, n - 1) {
			char ch = s[i];
			if (temp->childs.count(ch)) {
				temp = temp->childs[ch];
				temp->count++;
			} else {
				Node* new_node = new Node(ch);
				temp->childs[ch] = new_node;
				temp = new_node;
			}
		}
		temp->isEnd = true;
	}

	void dfs(Node* node, std::vector<char> &out) {
		if (node == NULL) return;
		if (node->count == 1 or node->isEnd) {
			out.push_back(node->ch);
			prefix.push_back(out);
			out.pop_back();
			return;
		}
		out.push_back(node->ch);
		iter_all(c, node->childs) {
			dfs(c.second, out);
		}
		out.pop_back();
	}

	std::vector<std::vector<char>> find_unique_prefix() {
		Node* temp = root;
		std::vector<char> a;
		iter_all(c, temp->childs) {
			dfs(c.second, a);
		}
		return prefix;
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
	std::vector<std::vector<char>> ans = tr.find_unique_prefix();
	iter_all(i, ans) {
		iter_all(j, i) {
			std::cout << j;
		}
		std::cout << ", ";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
/*
4
zebra
dog
duck
dove
*/