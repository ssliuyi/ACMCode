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
    bool isValidBSTUtil(TreeNode* root, int mmin, int mmax)
    {
        if(root == NULL) return true;
        if(mmin < root->val && root->val < mmax)
        {
            return isValidBSTUtil(root->left, mmin, root->val) 
                   && isValidBSTUtil(root->right, root->val, mmax);
        }
        else return false;
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mmin = INT_MIN;
        int mmax = INT_MAX;
        return isValidBSTUtil(root, mmin, mmax);
    }
};