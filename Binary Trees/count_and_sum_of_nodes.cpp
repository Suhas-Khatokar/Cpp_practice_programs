#include<iostream>
#include<queue>
#include<vector>
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
Node* buildTree(vector <int> preOrder) {
    idx++;
    Node *root = new Node(preOrder[idx]);
    if (preOrder[idx] == -1) return nullptr;
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

int countNodes(Node *root) {
    if (root == nullptr) return 0;
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);

    return leftNodes + rightNodes + 1;
}

int sumOfNodes(Node *root) {
    if (root == nullptr) return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);

    return leftSum + rightSum + root->val;
}



int main() {
    vector <int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(v);
    cout<<countNodes(root)<<endl;
    cout<<sumOfNodes(root);
    return 0;
}