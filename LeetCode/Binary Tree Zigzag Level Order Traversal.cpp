/*
 * =====================================================================================
 *
 *       Filename:  Binary Tree Zigzag Level Order Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/03/2014 02:32:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if( root == NULL )
        {
            return res;
        }
        queue<TreeNode *> q;
        vector<int> temp;
        q.push(root);
        q.push(NULL);
        bool tag = 0;
        while(1)
        {
            if( q.front() == NULL )
            {
                if( tag == 0 )
                {
                    res.push_back(temp);
                }
                else
                {
                    vector<int> temp2;
                    temp2.assign(temp.rbegin(), temp.rend());//注意assign的用法，必须新建temp2,不能利用其副作用。
                    res.push_back(temp2);
                }
                temp.clear();
                tag =(tag == 0?1:0);
                q.pop();
                if(q.size() == 0)
                {
                    break;
                }
                q.push(NULL);
            }
            else
            {
                temp.push_back(q.front()->val);
                //cout<<q.front()->val<<" ";
                if( q.front()->left != NULL )
                {
                    q.push(q.front()->left);
                }
                if( q.front()->right != NULL )
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }
        return res;
    }
};
int main(int argc, char *argv[])
{
    Solution s;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    s.zigzagLevelOrder(root);
}
