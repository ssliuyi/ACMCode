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
    void pt(TreeNode *root, vector<int> & v )
    {
         if(root != NULL)
        {
            v.push_back(root->val);
            pt(root->left,v);
            pt(root->right,v);
        }
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
        pt(root,v);
        return v;
    }
};