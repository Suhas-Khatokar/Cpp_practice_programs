#include <iostream>
using namespace std;

class Node {
    public:
    int val;
    Node *left;
    Node *right;

    Node(int data) {
        val = data;
        left = right = nullptr;
    }
};

bool searchKey(Node *root, int key) {
    if (root == nullptr) return false;
    if (root->val == key) return true;
    if (root->val > key) return searchKey(root->left, key);
    else return searchKey(root->right, key);
}


