#include<iostream>
using namespace std;

//Class is a user defined data type, you can write the prop of that data type inside it
class Node {
    public:
    int val;
    Node *next;
    //Every node of a linked list has two things: a value and A POINTER WHICH POINTS TO THE NEXT NODE
    //                                                       (basically stores the address of next node)   

    //Every constructor starts with the defined datatype and some parameter (if req) and its like a func
    Node (int data) {
        val = data;
        next = nullptr; //Its a null pointer
    }
};

//With the help of head pointer, we can access the entire linked list

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

void insertAtTail(Node *&head, int val) {
    //IMP - The constructor automatically sets next = nullptr.
    Node *end_node = new Node(val);

    // If the linked list is empty, make the new node the head.
    if (head == nullptr) {
        head = end_node;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // temp is now pointing to the last node.
    // Connect the last node to the new node.
    temp->next = end_node;
}

void insertAtAny(Node *&head, int val, int pos) {
    //Using 0 based pos
    //1->2->3->4->NULL
    //1->2->0->3->NUll (if val = 0 and pos = 2)

    if (pos == 0) {
        insertAtHead(head, val);
        return;
    }

    Node *new_node = new Node(val);
    Node *temp = head;
    int i=0;

    while (i<pos-1) {
        temp = temp->next;
        i++;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

void updateAtAny(Node *&head, int value, int pos) {
    Node *temp = head;
    int i=0;
    while (i<pos) {
        temp = temp->next;
        i++;
    }
    temp->val = value;
}

//1 2 3 4 NULL

void deleteAtAny(Node *&head, int pos) {
    if (pos == 0) {
        Node *temp = head;
        head = head->next;
        free(temp); //Frees up the memory taken by temp
        return;
    }

    Node *temp1 = head;
    int i=0;
    while (i<pos-1) {
        temp1 = temp1->next;
        i++;
    }
    Node *temp2 = temp1->next;
    Node *toDelete = temp2;
    temp2 = temp2->next;
    temp1->next = temp2;
    delete toDelete; //or use free(toDelete)
    //No need for pos at tail as this automatically takes care
}

int main() {

    //Accessing value and the next address
    // IMP POINT - n itself is a pointer which points to a node and the node points to the next node
    Node *n = new Node(1);
    cout<<n->val<<" "<<n->next<<endl;

    //OR 
    //Node n = Node(1); 
    //cout<<n.val<<" "<<n.next<<endl; but not recommended for linked list but can use for other classes

    Node *head = nullptr; //Empty linked list (head doesn't point to any node yet)
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtTail(head, 4);
    insertAtAny(head, 0, 2);
    //updateAtAny(head, 1, 3);
    deleteAtAny(head, 1);
    traverseLinkedList(head);

    //3->NULL
    //2->3->NULL
    //1->2->3->NULL

    return 0;
}