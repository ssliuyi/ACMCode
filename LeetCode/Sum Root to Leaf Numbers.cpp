#include <iostream>
#include <math>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
    public:
        int sn (TreeNode *root ,  int sum)
        {
            if( root == NULL )
            {
                return 0; 
            }
            sum = sum *10 + root->val;
            if( root->left == NULL && root->right == NULL)
            {
                return sum;
            }
            return sn (root->left, sum)+sn (root->right, sum);
        }

        int sumNumbers(TreeNode *root)
        {
            return sn(root, 0);
        }
};
