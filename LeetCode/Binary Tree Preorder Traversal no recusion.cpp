/*
 * =====================================================================================
 *
 *       Filename:  Binary Tree Preorder Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2014 07:22:27 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
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
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> res;
            stack<TreeNode *> st;
            TreeNode * p = root;
            st.push(p);
            if( root == NULL )
            {
                return res; 
            }
            while( st.size() != 0 )
            {
                p = st.top();
                st.pop();
                res.push_back(p->val);
                if( p->right != NULL )
                {
                    st.push(p->right);
                }
                if( p->left != NULL )
                {
                    st.push(p->left);
                }
            }
            return res;
        }
};
