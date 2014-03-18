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
    bool isSameTreeUtil(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;
        if(p->val == q->val)
        {
            return isSameTreeUtil(p->left, q->left) && isSameTreeUtil(p->right, q->right);
        }
        else return false;
    }
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return isSameTreeUtil(p, q);
    }
};