#include <iostream>
using namespace std;

class Node {
public: 
    int val;
    Node *next;
    Node *prev;

    Node (int value) {
        val = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
    public:
    Node *head;
    Node *tail;

    DoublyLinkedList () {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtHead (int val) {
        Node *new_node = new Node(val);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtEnd (int val) {
        Node *new_node = new Node(val);
        if (tail     == nullptr) {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void insertAtAny(int val, int pos) {
        //For 1 based indexing, for 0 based-> put i=0
        Node *temp = head;
        Node *new_node = new Node(val);
        for (int i=1; i<pos-1; i++) {
            temp = temp->next;
        }

        new_node->next = temp->next;
        temp->next->prev = new_node;
        temp->next = new_node;
        new_node->prev = temp;
        
    }

    void deleteAtHead() {
        if (head == nullptr) return;
        Node *toDel = head;
        head = head->next;
        if (head == nullptr) tail = nullptr; //doubly ll has only 1 node
        else head->prev = nullptr;

        delete toDel;
    }   

    void deleteAtEnd() {
        if (head == nullptr) return;
        Node *toDel = tail;
        tail = tail->prev;
        if (tail == nullptr) head = nullptr;
        else tail->next = nullptr;

        delete toDel;
    }

    void deleteAtAny(int pos) {
        Node *temp = head;
        for (int i=1; i<pos; i++) {
            temp = temp->next; //Going to the exact pos unlike singly ll
        }

        if (pos == 1) deleteAtHead();
        else if (temp == tail) deleteAtEnd();
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        
    }

    void display () {
        Node *temp = head;
        cout<<"NULL<-";
        while (temp != nullptr) {
            cout<<temp->val<<"<->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void reverse() {
        Node *curr = head;

        while (curr != nullptr) {
            Node *next_ptr = curr->next;
            curr->next = curr->prev;
            curr->prev = next_ptr;
            curr = next_ptr;
        }

        head = curr;
    }
};


int main() {
    DoublyLinkedList dll;
    dll.insertAtEnd(1);
    dll.insertAtEnd(2);
    dll.insertAtEnd(3);
    dll.insertAtEnd(4);
    dll.reverse();
    dll.display();

    return 0;
}