#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node (int val) {
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;
Node *buildTree (vector <int> preOrder) {
    idx++;  
    Node *root = new Node(preOrder[idx]);
    if (preOrder[idx] == -1) return nullptr;
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

void kth_level(Node *root, int k) {
    if (root == nullptr) return;

    if (k == 1) {
        cout<<root->data<<" ";
        return;
    }
    kth_level(root->left, k-1);
    kth_level(root->right, k-1);
}


int main() {
    vector <int> preorder_seq = {1, 2, -1, -1, 3, 4, -1,-1, 5, -1, -1};
    Node *root = buildTree(preorder_seq); 
    kth_level(root, 3);
    return 0;
}