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
    void pathSumone (TreeNode *root, int sum,int cursum,vector<vector<int> > & path,vector<int> & curpath) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(root==NULL) return;
        bool isleaf = root->left==NULL && root->right==NULL;
        cursum+=root->val;
        curpath.push_back(root->val);
        
        if(cursum==sum && isleaf)
        {
            path.push_back(curpath);
        }
        else
        {
            pathSumone(root->left,sum,cursum,path,curpath);
            pathSumone(root->right,sum,cursum,path,curpath);
        }
        cursum-=root->val;
        curpath.pop_back();
        
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > path;
        vector<int>  curpath;
        pathSumone (root,sum,0,path,curpath);
        return path;
    }
};