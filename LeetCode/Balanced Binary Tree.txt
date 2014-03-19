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
        bool isBalanced(TreeNode *root) {  
            // Note: The Solution object is instantiated only once and is reused by each test case.  
            int depth = 0;  
            return isbalance(root, depth);  
        }  
        bool isbalance(TreeNode *root, int &depth)  
        {  
            if(root == NULL)  
            {  
                depth = 0;  
                return true;  
            }  
            int ld,rd;  
            if( isbalance(root->left,ld) && isbalance(root->right,rd))  
            {  
                if( abs(ld - rd) > 1)  
                {  
                    return false;  
                }  
                depth = ld > rd ? ld + 1 : rd + 1;  
                return true;  
            }  
        }  
};
