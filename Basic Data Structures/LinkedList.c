#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insert(struct node* head, int data){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
    }

    struct  node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    temp->next = newNode;
    return head;
}

struct node* insertSorted(struct node* head, int data){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return head;
    }

    struct node* temp = head;
    struct node* prev = NULL;
    while(temp != NULL && temp->data < data){
        prev = temp;
        temp = temp->next;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp;
    prev->next = newNode;
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]){

    struct node* head = NULL;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 5);
    head = insert(head, 6);

    display(head);

    head = insertSorted(head, 3);

    display(head);
    
    return 0;
}
