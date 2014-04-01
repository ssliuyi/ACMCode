/*
 * =====================================================================================
 *
 *       Filename:  Construct Binary Tree from Preorder and Inorder Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2014 04:04:28 PM
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:

        TreeNode *creatTree(vector<int> &preorder,int prebeg, int preend,  vector<int> &inorder, int inbeg, int inend)
        {
            if( inbeg > inend )
            {
                return NULL;
            }

            int index = 0;
            int head = preorder[prebeg];

            for( int i = inbeg ; i <= inend ; i++ )
            {
                if( inorder[i] == head )
                {
                    index = i;
                    break;
                }
            }

            int len = index - inbeg;

            TreeNode *left = creatTree(preorder, prebeg+1, prebeg+len,inorder, inbeg, index-1);
            TreeNode *right = creatTree(preorder, prebeg+len+1, preend, inorder, index+1, inend);
            TreeNode *  node =  new TreeNode(head);
            node->left = left;
            node->right = right;
            return node;
        }

        TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
        {
            return creatTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        }
};
