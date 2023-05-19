#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int val) : data(val),left(NULL),right(NULL) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        vector<int> row;
        int n =  q.size();
        for(int i = 0; i < n; i ++) {
            TreeNode* tmp = root;
            q.pop();
            row.push_back(tmp->data);
            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        ans.push_back(row);
    }

    return ans;
}

int main() {
    struct TreeNode* root = new TreeNode(1);
    root -> left = new TreeNode(2);
    root -> left -> left = new TreeNode(4);
    root -> left -> right = new TreeNode(5);
    root -> right = new TreeNode(3);
    root -> right -> left = new TreeNode(6);
    root -> right -> right = new TreeNode(7);
    return 0;
}