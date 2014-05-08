/*
 * =====================================================================================
 *
 *       Filename:  Binary Tree Inorder Traversal no trivial.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 10:19:28 AM
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
#include <stack>
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
        vector<int> inorderTraversal(TreeNode *root) {
            vector<int> res;
            if( root == NULL )
            {
                return res;
            }
            TreeNode * tr = root;

            stack<TreeNode*> s;
            while(s.size()>0 || tr != NULL)
            {
                if(tr!=NULL)
                {
                    s.push(tr);
                    tr= tr->left;
                }
                else
                {
                    tr = s.top();
                    s.pop();
                    res.push_back(tr->val);
                    tr = tr->right;
                }
            }
            return res;
        }
};
