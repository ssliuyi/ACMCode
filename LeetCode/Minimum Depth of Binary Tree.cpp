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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(root == NULL) return 0;
        queue<TreeNode *> q;
        q.push(NULL);
        q.push(root);
        int level=0;
        while(q.size()>1)
        {
            if(q.front()==NULL)
            {
                level++;
                q.pop();
                q.push(NULL);
            }
            else
            {
                if(q.front()->left == NULL && q.front()->right == NULL) return level;
                else
                {
                    if(q.front()->left!=NULL)
                    {
                        q.push(q.front()->left);
                    }
                    if(q.front()->right!=NULL)
                    {
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
            }
            
        }
    }
};