// https://www.codingninjas.com/studio/problems/boundary-traversal_790725?leftPanelTab=0
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

/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

std::vector<int> ans;
void leftBound(TreeNode<int>* root){
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) return;

    ans.push_back(root->data);

    if(root->left){
        leftBound(root->left);
    } else {
        leftBound(root->right);
    }
}


void rightBound(TreeNode<int>* root){
    if(root == NULL) return;
    if(root->left == NULL and root->right == NULL) return;

    if(root->right){
        rightBound(root->right);
    } else {
        rightBound(root->left);
    }

    ans.push_back(root->data);
}


void preorder(TreeNode<int>* root){
    if(root == NULL) return;

    if(root->left == NULL and root->right == NULL)
        ans.push_back(root->data);

    preorder(root->left);
    preorder(root->right);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    if(root == NULL)
        return {};
    ans.push_back(root->data);
    leftBound(root->left);
    preorder(root);
    rightBound(root->right);

    return ans;
}


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