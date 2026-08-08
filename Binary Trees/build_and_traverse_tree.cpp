#include <iostream>
#include <vector>
using namespace std;

//Building a node of binary tree
//Binary trees have at max two children nodes [0, 1, 2]
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

void preOrderTraversal(Node *root) {

    if (root == nullptr) return;

    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


int main() {
    //preorder sequence is an array which linearly represents a tree
    vector <int> preorder_seq = {1, 2, -1, -1, 3, 4, -1,-1, 5, -1, -1};
    //THE SEQUENCE IS ROOT, LEFT , RIGHT 
    //-1 means node points to null
    //          1
    //     2        3
    //   N  N     4   5
    //          N  N N  N

    Node *root = buildTree(preorder_seq);
    preOrderTraversal(root);
    //1 2 3 4 5
    return 0;
}