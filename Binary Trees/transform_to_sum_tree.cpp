#include <iostream>
#include <vector>
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

static int idx = -1;
Node *buildTree(vector <int> preOrder) {
    idx++;
    Node *root = new Node(preOrder[idx]);
    if (preOrder[idx] == -1) return nullptr;
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

int sumTree(Node *root) {
    if (root == nullptr) return 0;
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    root->val = root->val + leftSum + rightSum;
    return root->val;
}

void preOrderTraversal(Node *root) {
    if (root == nullptr) return;
    cout<<root->val<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


int main() {
    vector <int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);
    cout<<sumTree(root)<<endl;
    preOrderTraversal(root);
    return 0;
}