<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* insert_back(int data, Node* head) {
    if (head == NULL) {
        Node* new_node = new Node(data);
        return new_node;
    }
    Node* new_node = new Node(data);
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* start;
int start_index = 0, len = 0;
void reverse(Node* end) {
    if (end->next) {
        ++len;
        reverse(end->next);
    }
    if (start_index > len / 2) {
        return;
    }
    std::swap(start->data, end->data);
    ++start_index;
    start = start->next;
}

int main() {
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        head = insert_back(d, head);
    }
    std::cout << "Linked List: ";
    display(head);
    start = head;
    std::cout << "\n";
    std::cout << "Reversed: ";
    reverse(head);
    display(head);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
=======
#include <bits/stdc++.h>
#define ll long long int

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* insert_back(int data, Node* head) {
    if (head == NULL) {
        Node* new_node = new Node(data);
        return new_node;
    }
    Node* new_node = new Node(data);
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void display(Node* head) {
    if (head == NULL) return;
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* start;
int start_index = 0, len = 0;
void reverse(Node* end) {
    if (end->next) {
        ++len;
        reverse(end->next);
    }
    if (start_index > len / 2) {
        return;
    }
    std::swap(start->data, end->data);
    ++start_index;
    start = start->next;
}

int main() {
    clock_t begin = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int d;
        std::cin >> d;
        head = insert_back(d, head);
    }
    std::cout << "Linked List: ";
    display(head);
    start = head;
    std::cout << "\n";
    std::cout << "Reversed: ";
    reverse(head);
    display(head);
#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
