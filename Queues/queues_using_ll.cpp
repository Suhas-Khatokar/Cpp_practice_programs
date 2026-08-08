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


class Queue {
    Node *head;
    Node *tail;

    public:
    Queue() {
        head = tail = nullptr;
    }

    void push(int val) {
        //Insert at tail
        Node *new_node = new Node(val);
        if (head == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void pop() {
        //Delete at head
        if (head == nullptr) {
            cout<<"Queue is empty";
            return;
        }
        else {
            Node *todel = head;
            head = head->next;
            delete todel;
        }
    }

    int front() {
        //Return head of LL
        if (head == nullptr) {
            cout<<"Queue is empty";
            return -1;
        }
        return head->val;
    }

    bool empty() {
        return head == nullptr;
    }

};


int main() {
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while (!q.empty()) {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}