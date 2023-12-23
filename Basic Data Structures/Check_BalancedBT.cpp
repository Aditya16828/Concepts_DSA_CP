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

std::pair<bool, int> isBBThelper(Node* root){
	if(root==NULL){
		return {true, 0};
	}

	std::pair<bool, int> chkl, chkr;
	chkl = isBBThelper(root->left);
	chkr = isBBThelper(root->right);
	bool temp = chkr.first and chkl.first and (abs(chkl.second-chkr.second) <= 1);
	return {temp, std::max(chkl.second, chkr.second)+1};
}

bool isBBt(Node* root){
	return isBBThelper(root).first;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Node* root = buildTree();
	std::cout<<(isBBt(root))<<"\n";

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

std::pair<bool, int> isBBThelper(Node* root){
	if(root==NULL){
		return {true, 0};
	}

	std::pair<bool, int> chkl, chkr;
	chkl = isBBThelper(root->left);
	chkr = isBBThelper(root->right);
	bool temp = chkr.first and chkl.first and (abs(chkl.second-chkr.second) <= 1);
	return {temp, std::max(chkl.second, chkr.second)+1};
}

bool isBBt(Node* root){
	return isBBThelper(root).first;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Node* root = buildTree();
	std::cout<<(isBBt(root))<<"\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}