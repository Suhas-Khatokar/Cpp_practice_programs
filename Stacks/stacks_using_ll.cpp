#include <iostream>
using namespace std;

class Stack {
private:
    class Node {
    public:
        int val;
        Node* next;

        Node(int data) {
            val = data;
            next = nullptr;
        }
    };

    Node* head = nullptr;

public:

    void push(int val) {
        //Insert at head
        Node *new_node = new Node(val);
        if (head == nullptr) head = new_node;
        else {
            new_node->next = head;
            head = new_node;
        }
    }

    void pop() {
        //Delete the head node
        if (head == nullptr) {
            cout<<"Underflow";
            return;
        }
        Node *toDel = head;
        head = head->next;
        delete toDel;
    }

    int top() {
        if (head != nullptr )return head->val;
    }

    bool empty() {
        if (head == nullptr) return true;
        else return false;
    }

};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    while (!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    //30, 20, 10
    return 0;
}