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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num=0;
        ListNode *q=head;
        while(q!=NULL)
        {
            q=q->next;
            num++;
        }
        if(num!=0) k=k%num;
        
        if(head==NULL||k==0) return head;
        ListNode *p1=head,*p2=head;
        
        for(int i=0;i<k && p1!=NULL;i++) p1=p1->next;
        if(p1==NULL) return head;
        
        while(p1->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
        }
      ListNode *p3=p2->next;
      p2->next=NULL;
      p1->next=head;
      return p3;
        
    }
};