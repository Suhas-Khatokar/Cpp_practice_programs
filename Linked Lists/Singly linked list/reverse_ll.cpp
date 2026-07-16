#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *next;

    Node (int data) {
        val = data;
        next = nullptr;
    }
};

void traverseBackwards(Node *head) {
    if (head == nullptr) return;
    traverseBackwards(head->next);
    cout<<head->val<<"->";
}

void traverse(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void reverseLL(Node *&head) {
    Node *curr = head;
    Node *prev = nullptr;

    while (curr!=nullptr) {
        Node *next_ptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_ptr;
    }

    head = prev;
}

void insertAtTail(Node *&head, int val) {
    Node *end_node = new Node(val);
    if (head == nullptr) {
        head = end_node;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = end_node;
}

int main() {
    Node *head = nullptr;
    for (int i=1; i<5; i++) {
        insertAtTail(head, i);
    }
    //traverseBackwards(head);
    //cout<<"NULL";
    reverseLL(head);
    traverse(head);
    return 0;
}