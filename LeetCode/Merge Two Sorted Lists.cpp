/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mtl(ListNode * l1,ListNode* l2, ListNode *m)
    {
        ListNode *result=m;
        if(l1==NULL) m->next=l2;
        else if(l2==NULL) m->next=l1;
        else
        {
            if(l1->val < l2->val)
            {
                m->next=l1;
                mtl(l1->next,l2,m->next);
            }
            else
            {
                m->next=l2;
                mtl(l1,l2->next,m->next);
            }
        }
        return result;
    }
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode m(1);
        mtl(l1,l2,&m);
        return m.next;
    }
};