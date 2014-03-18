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
    int MaxDepth(TreeNode *root,int cur_depth) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return cur_depth;
        //if(root->left==NULL &&root->right==NULL) return cur_depth+1;
        int a=MaxDepth(root->left,cur_depth+1);
        int b=MaxDepth(root->right,cur_depth+1);
        return a>b?a:b;
    }
    
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int cur_depth=0;
       return MaxDepth(root,0);
    }
};