#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val),left(NULL),right(NULL) {}
};
int mx = -1001;
int maxPathSum(TreeNode* root) {
    if(!root) return 0;

    int lsum = max(0,maxPathSum(root->left));
    int rsum = max(0,maxPathSum(root->right));

    mx = max(mx,root-data + lsum + rsum);

    return root->data + max(lsum,rsum);
}

int solve(TreeNode* root) {
    maxPathSum(root);

    return mx;
} 

int main() {
    struct TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    cout << solve(root);
    return 0;
}