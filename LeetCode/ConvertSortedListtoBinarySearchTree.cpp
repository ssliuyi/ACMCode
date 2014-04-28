/*
 * =====================================================================================
 *
 *       Filename:  ConvertSortedListtoBinarySearchTree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/27/2014 09:10:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LiuYi (), swliuyi@gamil.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int computeLen(ListNode * head)
    {
        int len = 0;
        for( ListNode * it = head ; it != NULL ; it = it->next )
        {
            len++;
        }
        return len;
    }

    TreeNode *buildBST(ListNode *head, int left, int right)
    {
        if( left > right )
        {
            return NULL;
        }
        int mid = (left + right)/2;
        ListNode *midListNode = head;
        for( int i = left ; i < mid ; i++ )//i = left
        {
            midListNode = midListNode->next;
        }

        TreeNode* midNode = new TreeNode(midListNode->val);
        midNode->left = buildBST(head, left, mid-1);
        midNode->right = buildBST(midListNode->next, mid+1, right);
        return midNode;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = computeLen(head);
        return buildBST(head, 0, len-1);
    }
};
