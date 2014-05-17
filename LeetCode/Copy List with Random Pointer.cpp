/*
 * =====================================================================================
 *
 *       Filename:  Copy List with Random Pointer.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2014 03:03:19 PM
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

//Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if( head == NULL )
        {
            return NULL;
        }

        for( RandomListNode * p = head ; p != NULL ; p = p->next )
        {
            RandomListNode * tmp  = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp; 
            p = tmp;
        }

        for( RandomListNode * p = head ; p != NULL ; p = p->next->next )
        {
            if( p->random != NULL )//the random point value may equal null
            {
                p->next->random = p->random->next;
            }
            else
            {
                p->next->random = NULL;
            }
        }

        RandomListNode * res = head->next;

        for( RandomListNode * p = head ; p != NULL ; p = p->next )
        {
            RandomListNode * tmp = p->next;
            p->next = p->next->next;
            if( tmp->next != NULL )
            {
                tmp->next = tmp->next->next;
            }
        }

        return res;
    }
};
int main(int argc, char *argv[])
{
   Solution s;
   RandomListNode * n1 = new RandomListNode(1);
   n1->random = n1;
   RandomListNode * n2 = new RandomListNode(2);
   n1->next = n2;
   n2->random = n1;
   RandomListNode * n3 = new RandomListNode(3);
   n2->next = n3;
   n1->next = NULL;
   RandomListNode * cp = s.copyRandomList(n1);
   for(  RandomListNode * p = cp ; p != NULL ; p = p->next )
   {
       cout<<p->label<<endl;
       cout<<p->random->label<<endl;
   }
}
