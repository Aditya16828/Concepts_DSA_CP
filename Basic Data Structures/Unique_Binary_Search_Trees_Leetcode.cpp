// https://leetcode.com/problems/unique-binary-search-trees/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

struct node{
    int val;
    node* left;
    node* right;
    node(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};

node* constructTree(int start, int end){
    if(start > end){
        return NULL;
    }
    node* root = new node(0);
    for(int i=start;i<=end;i++){
        node* leftTree = constructTree(start, i-1);
        node* rightTree = constructTree(i+1, end);
        root->val = i;
        root->left = leftTree;
        root->right = rightTree;
    }
    return root;
}

void inorder(node* root){
    if(root == NULL) return;

    inorder(root->left);
    std::cout<<root->val<<", ";
    inorder(root->right);
}

std::vector<node*> solve(int n){
    std::vector<node*> ans;
    for(int i=1;i<=n;i++){
        for(int k = 1;k < n;k++){
            node* lst = constructTree(1, i-k);
            node* rst = constructTree(i+k, n);
            node* root = new node(i);
            root->left = lst;
            root->right = rst;
            inorder(root);
            std::cout<<"\n";
            ans.push_back(root);
        }
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<node*> v(solve(n));
    // for(auto &i:v){
    //     inorder(i);
    //     std::cout<<"\n";
    // }

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
