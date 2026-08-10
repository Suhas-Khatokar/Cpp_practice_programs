#include <iostream>
#include <vector>
#include <queue>
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


//In order traversal works on the principle left, root, right
    //          1
    //     2        3
    //   N  N     4   5
    //          N  N N  N
    // 2 1 4 3 5

void inOrderTraversal(Node *root) {
    if (root == nullptr) return;

    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

//Post order traversal works on the principle left, right, root
    //          1
    //     2        3
    //   N  N     4   5
    //          N  N N  N
    // 2 4 5 3 1

void postOrderTraversal(Node *root) {
    if (root == nullptr) return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node *root) {
    // queue<Node*> stores addresses of tree nodes, so root can be pushed directly without dereferencing.
    // curr gets the pointer from the queue, accesses that node, then pushes its left/right child pointers.
    queue <Node *> q;
    q.push(root);

    while (q.size() > 0) {
        Node *curr = q.front();
        cout<<curr->data<<" ";
        q.pop();

        if (curr->left != nullptr) q.push(curr->left);
        if (curr->right != nullptr) q.push(curr->right);
    }
    
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
    cout<<endl;
    //1 2 3 4 5
    inOrderTraversal(root);
    cout<<endl;
    //2 1 4 3 5
    postOrderTraversal(root);
    cout<<endl;
    //2 4 5 3 11
    levelOrderTraversal(root);
    //1 2 3 4 5
    return 0;
}