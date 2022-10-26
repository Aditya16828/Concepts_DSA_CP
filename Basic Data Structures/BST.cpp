#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
	}
};

Node* insert(Node* root, int data) {
	if (root == NULL) {
		Node* node = new Node(data);
		return node;
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else {
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder_print(Node* root) {
	if (root == NULL) return;
	inorder_print(root->left);
	std::cout << root->data << ", ";
	inorder_print(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
        return;
    std::cout<<(root->data)<<", ";
    preorder(root->left);
    preorder(root->right);
}

std::queue<Node*> max_depth_nodes(Node* root) {
	std::queue<Node*> nodes;
	std::queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while (not q.empty()) {
		Node* curr = q.front();
		q.pop();
		if (q.empty()) break;
		if (curr == NULL and not q.empty()) {
			nodes = q;
			q.push(NULL);
			continue;
		}
		if (curr->left) q.push(curr->left);
		if (curr->right) q.push(curr->right);
	}
	return nodes;
}

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int d = 0;
	std::cin >> d;
	Node* root = NULL;
	while (d != -1) {
		root = insert(root, d);
		std::cin >> d;
	}
	preorder(root);
	std::cout << "\n\n";
	std::queue<Node*> temp = max_depth_nodes(root);
	while (temp.size()) {
		std::cout << temp.front()->data << ", ";
		temp.pop();
	}
	std::cout << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}