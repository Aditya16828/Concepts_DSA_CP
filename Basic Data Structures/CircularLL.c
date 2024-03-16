#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* insertFront(struct node* head, int data){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = head;
        return head;
    }

    struct node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }
    
    

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    temp->next = newNode;
    head = newNode;
    return head;
}

struct node* insertEnd(struct node* head, int data){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = head;
    }

    struct node* temp = head;
    while (temp->next != head){
        temp = temp->next;
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    temp->next = newNode;
    return head;
}

struct node* insert(struct node* head, int data, int idx){
    if(head == NULL){
        head = (struct node*)malloc(sizeof(struct node));
        head->data = data;
        head->next = NULL;
        return head;
    }

    if(idx == 0){
        return insertFront(head, data);
    }

    struct node* temp = head;
    int i = 0;
    while(temp->next != head && i < idx){
        temp = temp->next;
        i++;
    }

    if(temp->next == head){
        return insertEnd(head, data);   
    }

    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct node* delete(struct node* head, int idx){
    if(head == NULL){
        return head;
    }

    if(idx == 0){
        struct node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        return head;
    }

    struct node* temp = head;
    int i = 0;
    while(temp->next != head && i < idx-1){
        temp = temp->next;
        i++;
    }

    if(temp->next == head){
        return head;
    }

    struct node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    return head;
}

struct node* deleteEnd(struct node* head){
    if(head == NULL){
        return head;
    }

    struct node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }

    struct node* toDelete = temp->next;
    temp->next = head;
    free(toDelete);
    return head;
}

struct node* deleteFront(struct node* head){
    if(head == NULL){
        return head;
    }

    struct node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    struct node* toDelete = head;
    head = head->next;
    temp->next = head;
    free(toDelete);
    return head;
}

void display(struct node* head){
    struct node* temp = head;
    while(temp->next != head){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n\n\n");
}

int main(int argc, char const *argv[]){

    struct node* head = NULL;
    head = insertFront(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 4);
    head = insert(head, 5, 2);
    head = insert(head, 6, 1);
    head = insert(head, 8, 1);
    head = insert(head, 23, 1);
    head = insert(head, 45, 1);

    display(head);

    delete(head, 2);

    display(head);

    deleteEnd(head);

    display(head);

    head = deleteFront(head);

    display(head);
    
    return 0;
}
