#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

node* insert(int data, node* root){
	node* n = (node*)malloc(sizeof(node));
	if(root == NULL) {
		n->data = data;
		n->next = NULL;
		return n;
	}

	n->data = data;
	n->next = NULL;
	node* temp = root;
	while(temp->next){
		temp = temp->next;
	}
	temp->next = n;
	return root;
}

void print(node* root){
	node* temp = root;
	while(temp){
		printf("%d, ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

node* delete_(node* root){
	node* prev = NULL;
	node* curr = root;
	node* foll = root->next;
	while(foll->next){
		prev = curr;
		curr = foll;
		foll = foll->next;
	}
	prev->next = foll;
	free(curr);
	return root;
}

int main(){
	int n;
	scanf("%d", &n);
	node* root = NULL;
	for(int i=0;i<n;i++){
		int d;
		scanf("%d", &d);
		root = insert(d, root);
	}
	print(root);
	root = delete_(root);
	print(root);
	return 0;
}