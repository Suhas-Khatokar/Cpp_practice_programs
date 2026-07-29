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

class CircularLL {
    public:
    Node *head;

    CircularLL () {
        head = nullptr;
    }

    void display() {
        Node *temp = head;
        do
        {
            cout<<temp->val<<"->";
            temp = temp->next;
        } while (temp != head);
        

    }

    void insertAtHead(int val) {
        Node *new_node = new Node(val);
        if (head == nullptr) {
            head = new_node;
            new_node->next = head; //For even a single element to behave like circular ll
            return;
        }

        //Traversing to get tail
        Node *tail = head;
        while (tail->next != head) {
            tail = tail->next;
        }
        new_node->next = head;
        tail->next = new_node;
        head = new_node;
    }


};




int main() {

    return 0;
}