class Solution {
public:
    bool findpath(TreeNode *root ,int sum,int cur_sum)
    {
        if(root==NULL) return 0;
        cur_sum += root->val;
        if(cur_sum == sum && root->left==NULL && root->right==NULL)
        {
            return 1;
        }
        else
        {
            return findpath(root->left,sum,cur_sum)+findpath(root->right,sum,cur_sum);
        }
        //cur_sum -= root->val;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur_sum=0;
        return findpath(root,sum,cur_sum);
        
    }
};