#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val),left(NULL),right(NULL) {}
};


int height(TreeNode* root, int &diam) {
    if(!root) return 0;
    int lh = height(root->left, diam);
    int rh = height(root->right, diam);

    diam = max((lh+rh),diam);

    return max(lh,rh)+1;
}

int diameterOfBinaryTree(TreeNode* root) {
    int diam = INT_MIN;
    height(root, diam);

    return diam;
}

int main() {
    struct TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    cout << diameterOfBinaryTree(root);
    return 0;
}