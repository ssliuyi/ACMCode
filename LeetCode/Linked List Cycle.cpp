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
    bool hasCycle(ListNode *head) {
        ListNode* onestep = head;
        ListNode* twostep = head;
        int time = 0;
        if(head == NULL || head->next == NULL) return 0;
        while(twostep != NULL && twostep->next != NULL)
        {
            onestep = onestep->next;
            twostep = twostep->next->next;
            if(onestep == twostep)
            {
                return 1;
            }
        }
        return 0;
    }
};