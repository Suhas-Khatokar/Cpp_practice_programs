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

int heightOfTree(Node *root) {
    if (root == nullptr) return 0;
    

    int leftHt = heightOfTree(root->left);
    int rightHt = heightOfTree(root->right);
    // Height = 1 for current node + height of taller subtree
    return max(leftHt, rightHt) + 1;
}


int main() {
    vector <int> v = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(v);
    cout<<heightOfTree(root);
    return 0;
}