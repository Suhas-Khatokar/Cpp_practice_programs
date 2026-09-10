#include <iostream>
#include <vector>
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

//Binary search trees follow a specific sequence where
// 1. Left node has lesser value than root and right node has greater value than root (left<root<right)
// 2. Inorder sequence is in sorted order
// 3. All the values are unique

Node *insert(Node *root, int n) {
    if (root == nullptr) return new Node(n);

    if (n < root->val) root->left = insert(root->left, n); 
    else root->right = insert(root->right, n);

    return root;
}

Node *buildBST(vector <int> arr) {
    Node *root = nullptr;
    for (int x : arr) {
        root = insert(root, x);
    }

    return root;
}

void inorder(Node *root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}


int main() {
    vector <int> v = {3, 2, 1, 5, 6, 4};
    Node *root = buildBST(v);
    inorder(root);
    return 0;
}