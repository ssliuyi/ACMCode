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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
       
        vector<vector<int>> result;
        vector<vector<int>> result2;
        if(root==NULL) return result2;
        vector<int> temp;
        queue<TreeNode * > q;
        q.push(NULL);
        q.push(root);
        //temp.push(root->val);
        while(q.size()>1)
        {
            if(q.front()==NULL)
            {
                q.pop();
                q.push(NULL);
                if(temp.size()!=0) result.push_back(temp);
                temp.clear();
            }
            else
            {
                if(q.front()->left!=NULL)q.push(q.front()->left);
                if(q.front()->right!=NULL)q.push(q.front()->right);
                temp.push_back(q.front()->val);
                q.pop();
            }
        }
        if(temp.size()!=0) result.push_back(temp);
        for(int i=result.size()-1;i>=0;i--)result2.push_back(result.at(i));
        return result2;
        
    }
};