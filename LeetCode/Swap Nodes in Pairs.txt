class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return head;//0个节点
        if(head->next==NULL)//1个节点
        {
            return head;
        }
        if(head->next->next==NULL)//2个节点
        {
            ListNode *temp=head->next;
            head->next->next=head;
            head->next=NULL;
            return temp;
        }
        //三个以上
        ListNode *p3=head,*p2=head->next,*p1=p2->next;
        head=head->next;
       while(1)
       {
           if(p3->next==NULL)//
            {
                return head;
            }
            if(p2->next==NULL)
            {
                p2->next=p3;
                p3->next=NULL;
                return head;
            }
            if(p1->next==NULL)
            {
                p3->next=p1;
                p2->next=p3;
                return head;
            }
            p3->next=p1->next;
            p2->next=p3;
            p3=p1;
            if(p1->next!=NULL) p2=p3->next;
            if(p2->next!=NULL) p1=p2->next;
       }
    }
};






class Solution {
    public:
        ListNode *swapPairs(ListNode *head) {
        
        if(head == NULL)        return NULL;
        if (head->next == NULL)  return head;
        
        ListNode * nextList = swapPairs(head->next->next);
        ListNode * p2 = head->next;
        head->next = nextList;
        p2->next = head;
        return p2; // return the new head

    }
};