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

void deleteDuplicates (Node *&head) {
    Node *temp = head;
    while (temp != nullptr) {
        Node *temp2 = temp->next;
        if (temp2 == nullptr) break;
        if (temp->val == temp2->val) {
            Node *toDel = temp2;
            temp->next = temp->next->next;
            delete toDel;
        }
        while (temp->next != nullptr && temp->val == temp->next->val) {
            Node *toDel = temp->next;
            temp->next = temp->next->next;
            delete toDel;
        }
        temp = temp->next;
    }  
}

void traverseLinkedList(Node *head) {
    Node *temp = head;

    while (temp != nullptr) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void insertAtHead(Node *&head, int val) {
    Node *new_node = new Node(val); //Assigning value to new node
    new_node->next = head; // Linking the new node's pointer to the first node
    head = new_node; //Making the new_node as the head
}

int main() {
    Node *head = nullptr;
    insertAtHead(head, 1);
    insertAtHead(head, 1);
        insertAtHead(head, 1);

    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    insertAtHead(head, 1);
    traverseLinkedList(head);
    deleteDuplicates(head);
    cout<<endl;
    traverseLinkedList(head);
    return 0;
}