#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *insert(int val, struct Node *root){
    if (root == NULL){
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node*));
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    if (val < root->data){
        root->left = insert(val, root->left);
    } else {
        root->right = insert(val, root->right);
    }
    return root;
}

void inorder(struct Node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node* remove_node(int d, struct Node* root){
    if(root == NULL){
        return root;
    }

    if(d < root->data){
        root->left = remove_node(d, root->left);
        return root;
    } else if(d > root->data){
        root->right = remove_node(d, root->right);
        return root;
    } else if (root->data == d) {
        struct Node* temp = NULL;
        if(root->left == NULL && root->right == NULL){
            free(root);
            return temp;
        } else if (root->left == NULL) {
            temp = root->right;
            root->right = NULL;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            temp = root->left;
            root->left = NULL;
            free(root);
            return temp;
        } else {
            int min_in_rst = __INT_MAX__;
            temp = root->right;
            while(temp){
                min_in_rst = min_in_rst > temp->data ? temp->data : min_in_rst;
                temp = temp->left;
            }
            root->data = min_in_rst;
            root->right=remove_node(min_in_rst, root->right);
            return root;
        }
    } else return NULL;
}

int main(){
    int d;
    scanf("%d", &d);
    struct Node *root = NULL;
    while (d != -1){
        root = insert(d, root);
        scanf("%d", &d);
    }
    inorder(root);
    root = remove_node(3, root);
    printf("\n\n");
    inorder(root);
    return 0;
}

/*
10
5
1
8
20
30
15
6
9
7
-1
*/