#include<iostream>
using namespace std;


/*Given the root of a binary tree, return the number of nodes where the value of the
  node is equal to the average of the values in its subtree.*/
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

int nodeCount = 0;

int avgAndCount(Node *root, int &count) {
    if (root == nullptr) {
        count = 0;
        return 0;
    }

    int leftCount;
    int rightCount;
    int leftSum = avgAndCount(root->left, leftCount);
    int rightSum = avgAndCount(root->right, rightCount);
    count = leftCount + rightCount + 1;
    int sum = leftSum + rightSum + root->val;

    if (sum/count == root->val) nodeCount++;

    return sum;

}


int averageOfSubtree(Node* root) {
    

}
int main() {
    return 0;
}