
class Solution {
public:
 
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	ListNode * p= l1; ListNode *q=l2;
        ListNode * k =new ListNode(0);
        ListNode * r=k;
        int remain=0;
        
        for(;p!=NULL&&q!=NULL; p=p->next,q=q->next)
        {    
            
			int sss;
			sss=(p->val+q->val+remain);
			r->next =new ListNode (sss%10);
            r=r->next;
            remain=sss/10;
        }
        if(p!=NULL)
        {
            for(;p!=NULL; p=p->next)
            {    
               
    	    	int sss;
		    	sss=(p->val + remain);
		    	r->next =new ListNode (sss%10);
                r=r->next;
                remain=sss/10;
            }
        }
        if(q!=NULL)
        {
            for(;q!=NULL; q=q->next)
            {    
               
            	int sss;
		    	sss=(q->val + remain);
		    	r->next =new ListNode (sss%10);
                r=r->next;
                remain=sss/10;
            }
        }
        if(remain!=0) 
        {
            r->next =new ListNode (1);
          //  k->next=NULL;
         
        }
       
        return k->next;
    }
}; 