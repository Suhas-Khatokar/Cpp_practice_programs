#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node *right;

    Node (int data) {
        val = data;
        left = right = nullptr;
    }
};

bool isSameTree(Node* p, Node* q) {

    if (p==nullptr || q==nullptr) return p==q;

    bool isleftSame = isSameTree(p->left, q->left);
    bool isrightSame = isSameTree(p->right, q->right);
    return isleftSame && isrightSame && (p->val == q->val);
}