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
    void build(vector<int> &num, TreeNode * &root, int left, int right)
    { 
        if(left>right)
            return;
        int mid = (left+right)/2;
        root = new TreeNode(num[mid]);
        build(num, root->left, left, mid-1);
        build(num, root->right, mid+1, right);
    }
    TreeNode *sortedArrayToBST(vector<int> &num) 
    {
        TreeNode * root= NULL ;
        build(num,root,0,num.size()-1);
        return root;
    }
};
