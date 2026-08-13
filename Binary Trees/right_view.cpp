#include <iostream>
#include <vector>
#include <queue>
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

vector <int> rightView (Node *root) {
    vector <int> ans;
    vector <Node *> nodes;
    queue <Node *> q;
    q.push(root);
    q.push(nullptr);
    while (q.size()>0) {
        Node *curr = q.front();
        q.pop();
        nodes.push_back(curr);

        if (curr == nullptr) {
            if (!q.empty()) q.push(nullptr);
            else break;
        } else {
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }    
    }

    for (int i=0; i<nodes.size()-1; i++) {
        if (nodes[i+1] == nullptr) ans.push_back(nodes[i]->val);
    }

    return ans;
}