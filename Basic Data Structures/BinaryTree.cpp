#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)                                 \
    {                                                \
        std::string _s = #args;                      \
        replace(_s.begin(), _s.end(), ',', ' ');     \
        std::stringstream _ss(_s);                   \
        std::istream_iterator<std::string> _it(_ss); \
        err(_it, args);                              \
    }
#define logarr(arr, a, b)             \
    for (int z = (a); z <= (b); z++)  \
        std::cout << (arr[z]) << " "; \
    std::cout << std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define rloop(i, a, b) for (int i = a; i >= b; i--)
#define iter_all(el, cont) for (auto &el : cont)

void err(std::istream_iterator<std::string> it) {}
template <typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args)
{
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

void file_i_o()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
    }
};

Node *buildTree()
{
    int d;
    scanf("%d", &d);
    if (d == -1)
    {
        return NULL;
    }
    Node *root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int countnodes(Node *root)
{
    if (root == NULL)
        return 0;
    int l = countnodes(root->left);
    int r = countnodes(root->right);
    return 1 + l + r;
}

int height(Node *root)
{ // TC -> O(n)
    if (root == NULL)
        return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    return 1 + (hl > hr ? hl : hr); // on the basis of no. of nodes
}

int sum_tilt = 0;
int tilt(Node *root)
{ // returns sum of nodes
    if (root == NULL)
        return 0;

    int sum_left = tilt(root->left);
    int sum_right = tilt(root->right);
    sum_tilt += abs(sum_left - sum_right);
    return sum_left + sum_right + root->data;
}

void levelorderlevelwise(Node* root){
    std::queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(not q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            printf("\n");
            if(not q.empty())
                q.push(NULL);
            continue;
        }
        printf("%d ", temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(int argc, char const *argv[])
{
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    Node* root = buildTree();
	
    printf("Preorder: \n");
	preorder(root);
	
    printf("\n\nInorder: \n");
	inorder(root);
	
    printf("\n\nPostorder: \n");
	postorder(root);
    
    printf("\n\nNumber of nodes: \n%d", countnodes(root));
    
    printf("\n\nHeight: \n%d", height(root));

    tilt(root);
    printf("\n\nSum of Tilt: %d\n\n", sum_tilt);

    printf("Levelorder: \n");
    levelorderlevelwise(root);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    // std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}