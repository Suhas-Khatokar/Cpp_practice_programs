#include<iostream>
#include<vector>
#include<queue>
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

Node *buildTree(vector <int> po) {
    idx++;
    if (po[idx] == -1) return nullptr;
    Node *root = new Node(po[idx]);
    root->left = buildTree(po);
    root->right = buildTree(po);

    return root;
}
//O(n) space complexity
queue <Node *> nodes;
queue <Node *> queueNodes(Node* root) {
    if (root == nullptr) return nodes;
    nodes.push(root);
    queueNodes(root->left);
    queueNodes(root->right);
    return nodes;
}
void flatten(Node* root) {
    queue <Node *> q = queueNodes(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (q.empty()) {
            curr->left = curr->right = nullptr;
            break;
        }
        curr->right = q.front();
        curr->left = nullptr;
    }
}

