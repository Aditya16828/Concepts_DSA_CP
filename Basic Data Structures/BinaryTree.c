#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* buildTree(){
	int d;
	scanf("%d", &d);
	if(d == -1){
		return NULL;
	}
	struct Node* root = (struct Node*)malloc(sizeof(struct Node*));
	root->data = d;
	root->left = buildTree();
	root->right = buildTree();
	return root;
}

void preorder(struct Node* root){
	if(root == NULL) return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct Node* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void inorder(struct Node* root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int countnodes(struct Node* root){
    if(root == NULL) return 0;
    int l = countnodes(root->left);
    int r = countnodes(root->right);
    return 1+l+r;
}

int height(struct Node* root){ // TC -> O(n)
    if(root == NULL) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    return 1+(hl > hr ? hl : hr); // on the basis of no. of nodes
}

int sum_tilt = 0;
int tilt(struct Node* root){ // returns sum of nodes
    if(root == NULL) return 0;

    int sum_left = tilt(root->left);
    int sum_right = tilt(root->right);
    sum_tilt += abs(sum_left-sum_right);
    return sum_left+sum_right+root->data;
}

void levelorder_levelwise(struct Node* root){
    
}

int main(void) {
	struct Node* root = buildTree();
	
    printf("Preorder: \n");
	preorder(root);
	
    printf("\n\nInorder: \n");
	inorder(root);
	
    printf("\n\nPostorder: \n");
	postorder(root);
    
    printf("\n\nNumber of nodes: \n%d", countnodes(root));
    
    printf("\n\nHeight: \n%d", height(root));

    tilt(root);
    printf("\n\nSum of Tilt: %d\n", sum_tilt);
    
  	return 0;
}

/*
1
2
4
-1
-1
-1
3
5
-1
6
7
-1
-1
8
-1
-1
-1
*/