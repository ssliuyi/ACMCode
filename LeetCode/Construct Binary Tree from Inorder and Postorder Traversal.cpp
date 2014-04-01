/*
 * =====================================================================================
 *
 *       Filename:  Construct Binary Tree from Inorder and Postorder Traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2014 03:42:15 PM
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
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        TreeNode *createTree(vector<int> &inorder, int inBeg, int inEnd, vector<int> &postorder, int postBeg, int postEnd)  
        {

            if (inBeg > inEnd)  return NULL;
            int root = postorder[postEnd];
            int index;

            for(int i = inBeg; i <= inEnd; i++)
            {
                if (inorder[i] == root)
                {
                    index = i;
                    break;
                }
            }

            int len = index - inBeg;
            TreeNode *left = createTree(inorder, inBeg, index - 1, postorder, postBeg, postBeg + len - 1);
            TreeNode *right = createTree(inorder, index + 1, inEnd, postorder, postBeg + len, postEnd - 1);
            TreeNode *node = new TreeNode(root);
            node->left = left;
            node->right = right;
            return node;
        }
        TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
        {
            return createTree(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1); 
        }
};
