#include<iostream>
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

void insertAtHead(Node *&head, int val) {
    Node *temp = new Node(val);
    temp->next = head;
    head = temp;
}

void deleteAlternate(Node *&head) {
    Node *curr = head;

    while (curr != nullptr && curr->next != nullptr) {
        Node *toDelete = curr->next;      // Save node to delete
        curr->next = curr->next->next;    // Skip over it
        delete toDelete;                  // Free memory
        curr = curr->next;                // Move to next remaining node
    }
}

void traverse(Node *head) {
    Node *temp = head;

    while (temp != nullptr) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}




int main() {
    Node *head = nullptr;
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    deleteAlternate(head);
    traverse(head);
    return 0;
}