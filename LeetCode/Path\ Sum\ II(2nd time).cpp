#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class Solution {
    public:
        void ps(TreeNode *root, int sum, int target, vector<int> path, vector<vector<int> > &res)
        {
            if(root == NULL)
            {
                return;
            }
            path.push_back(root->val);
            sum += root->val;
            ps(root->left, sum, target,  path, res);
            ps(root->right, sum, target,  path, res);
            if( root->left == NULL && root->right == NULL && sum == target)
            {
                res.push_back(path);
                return;
            }
        }
        vector<vector<int> > pathSum(TreeNode *root, int sum) {
            vector<int> path;
            vector<vector<int> > res;
            ps(root, 0, sum, path, res);
            return res;
        }
};
