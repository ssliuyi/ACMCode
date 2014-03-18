/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void T(TreeNode * root,vector<int> & r)
    {
        if(root==NULL) return;
        T(root->left,r);
        r.push_back(root->val);
        T(root->right,r);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r;
        T(root,r);
        return r;
    }
};