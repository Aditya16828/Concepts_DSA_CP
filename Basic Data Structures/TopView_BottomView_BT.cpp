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

struct Node{
	int data;
	Node* left;
	Node* right;

	Node(int d){
		this->data = d;
	}
};

Node* buildTree(){
	int d;
	std::cin>>d;
	if(d == -1){
		return NULL;
	}
	
	Node* root = new Node(d);
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

std::map<int, int> mp;

void helper_tv(Node* root, int i){
	if(root == NULL){
		return;
	}
	if(mp.count(i) == 0){
		mp[i] = root->data;
	}
	helper_tv(root->left, i-1);
	helper_tv(root->right, i+1);
}

void top_view(Node* root){
	int i = 0;
	helper_tv(root, i);
	for(auto i:mp){
		std::cout<<i.second<<", ";
	}
}

void helper_bv(Node* root, int i){
	if(root == NULL){
		return;
	}

	mp[i] = root->data;
	helper_bv(root->left, i-1);
	helper_bv(root->right, i+1);
}

void bottom_view(Node* root){
	int i=0;
	helper_bv(root, i);
	for(auto i: mp){
		std::cout<<i.second<<", ";
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Node* root = buildTree();
	top_view(root);
	std::cout<<"\n";
	bottom_view(root);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}