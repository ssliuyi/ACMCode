/*
 * =====================================================================================
 *
 *       Filename:  Linked List Cycle II.cpp
 *
 *    Description:  LeetCode
 *
 *        Version:  1.0
 *        Created:  03/31/2014 12:52:42 PM
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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *meetposition(ListNode *head)
        {
            if( head == NULL )
            {
                return NULL;
            }

            ListNode * p = head;
            ListNode * q = head;
            while( q != NULL && q->next != NULL )
            {
                p = p->next;
                q = q->next->next;
                if( p == q )
                {
                    return p;
                }
            }
            return NULL;
        }

        ListNode *detectCycle(ListNode *head)
        {
            ListNode * meetp = meetposition(head);
            if( meetp == NULL )
            {
                return NULL;
            }
            else
            {
                ListNode * p = head;
                while( p != meetp )
                {
                    p = p->next;
                    meetp = meetp->next;
                }
                return p;
            }
        }
};
