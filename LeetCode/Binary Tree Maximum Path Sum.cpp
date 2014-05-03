/*
 * =====================================================================================
 *
 *       Filename:  Binary Tree Maximum Path Sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/02/2014 07:37:58 PM
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
    int mPS(TreeNode * root, int & myMax)
    {
        if( root == NULL )
        {
            return 0;
        }
        int left = mPS(root->left, myMax);
        int right = mPS(root->right, myMax);
        int res = root->val;
        if( left > 0 )
        {
            res += left;
        }
        if( right > 0 )
        {
            res += right;
        }
        myMax = max(res, myMax);
        return max(root->val, max(root->val+left,root->val+right));  
    }
    int maxPathSum(TreeNode *root) 
    {
        int myMax = root->val;
        int val =  mPS(root, myMax);
        return max(myMax, val);
    }
};
