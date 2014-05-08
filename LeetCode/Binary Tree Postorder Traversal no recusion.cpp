class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ans;
        list<TreeNode*> node_list;
        if(root == NULL) return ans;
        node_list.push_front(root);
        TreeNode *head = root;
        while(!node_list.empty())
        {
            TreeNode *cur = node_list.front();
            if(cur -> right == head || cur -> left == head || ((cur -> right == NULL) && (cur -> left == NULL)))
            {
                node_list.pop_front();
                ans.push_back(cur -> val);
                head = cur;
            }
            else
            {
                if(cur -> right != NULL) node_list.push_front(cur -> right);
                if(cur -> left != NULL) node_list.push_front(cur -> left);
            }
        }
    }
};
