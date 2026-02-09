//lc 61
//approach
// if n is no of total nodes then after every n shifts list becomes same to original
// find effective no of shifts : k % n  (k now becomes in range [0,n-1])
// if effective shift is 0 then list remains same
// if effective shift is k then the kth node from back (1 based indexing)  or n-k+1th node from front (1 based indexing )  in original list becomes the head of the new list


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {

        if(head==NULL||head->next==NULL||k==0) return head;

        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }   // cnt gives total no of nodes
        
        k=k%cnt; //effective rotates

        if(k==0) return head; 

        ListNode* front=head;
        ListNode* back=head;

        //front ko last node pe lejao 
        //back ko kth node from back ke prev node pe lejao
       while(front->next!=NULL) front=front->next;
       for(int i=1;i<cnt-k;i++) back=back->next;

    // or

        // using delayed start method (learned in lc 19) to reach prev node of kth node from back
        // ListNode* front=head;
        // ListNode* back=head;
       
        // for(int i=1;i<=k;i++){
        //     front=front->next;
        //      }
        //  while(front->next!=NULL){
        //     front=front->next;
        //     back=back->next;
        //  }    


         // front is on last node
         // back is on prev node of kth node

         front->next=head;// connect last to first
         head=back->next; // make kth node as head
         back->next=NULL; // point prev node of kth node to null

         return head;
  
        
    }
};