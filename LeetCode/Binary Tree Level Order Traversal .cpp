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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        queue<TreeNode*> q;
        q.push(NULL);
        vector<vector<int>> result;
        vector<int> temp;
        if(root == NULL)return result;
        else
        {
            q.push(root);
            while(q.size()!=1)
            {
             while(q.front()!=NULL)
             {
                 temp.push_back(q.front()->val);
                 if(q.front()->left!=NULL) q.push(q.front()->left);
                 if(q.front()->right!=NULL) q.push(q.front()->right);
                 q.pop();
             }
             if(q.front()==NULL)
             {
               q.pop();
               q.push(NULL);
             }
             if(temp.size()!=0) result.push_back(temp);
             temp.clear();
            }
        }
     return result;   
    }
};