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

std::pair<bool, pii> checkBSThelper(Node* root){
	if(root == NULL){
		return {true, {INT_MIN, INT_MAX}};
	}
	std::pair<bool, pii> chkl, chkr;
	chkl = checkBSThelper(root->left);
	chkr = checkBSThelper(root->right);
	bool temp = (chkl.first and chkr.first and chkr.second.second > root->data and chkl.second.first < root->data);
	int maximum = std::max({chkl.second.first, chkr.second.first, root->data});
	int minimum = std::min({chkl.second.second, chkr.second.second, root->data});
	return {temp, {maximum, minimum}};
}

bool isBST(Node* root){
	bool temp = checkBSThelper(root).first;
	return temp;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Node* root = buildTree();
	std::cout<<(isBST(root))<<"\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}