//lc 19

// need to remove nth node from back (1 based indexing)

// https://youtu.be/3kMKYQ2wNIU?si=bF-m6esq8-95jNmB

//m1



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp=head;
        int cnt=1;
        while(temp->next!=NULL){
            temp=temp->next;
            cnt++;
        }
        
         int remove=cnt-n+1;
      
      temp=head;

         if(remove==1){ // first node remove
            head=head->next;
            temp->next=NULL;
            return head;
         }

        int count=1;
        
        while(count!=remove-1){
            
            temp=temp->next;
            count++;
        }
        //temp is at one node previous to node jise remove krna
        ListNode* del=temp->next;
        temp->next=del->next;
        del->next=NULL;

        return head;

    }
};


// m2 :reach behind node of nth node from back in one pass (total nodes is not required)

//delayed start method 
// helps in travelling to nth node from back in one pass (ie total nodes nikalne ki no need)
// ->Maintain two pointers and dono ko start pe rkhdo . ek ko initially n steps bhadado from beginning node. fir dono ko saath ek ek bhadate jao and when aage wali node reaches null then behind one will reach the nth node from back 
//note: if initially n aage bhadane mein aage wali reaches null ->nth node from back is 1st node (back wali 1st node pe hi h)


//this can be used to reach behind node of nth node from back in one pass
//// ->Maintain two pointers and dono ko start pe rkhdo . ek ko initially n steps bhadado from beginning node. fir dono ko saath ek ek bhadate jao and when aage wali node reaches end node then behind one will reach the prev node of nth node from back 
//note: if initially n aage bhadane mein aage wali reaches end node ->prev node of nth node from back is 1st node (back wali 1st node pe hi h )
//note: if initially n aage bhadane mein aage wali reaches null ->nth node from back is 1st node (back wali 1st node pe hi h ...back wali is pointing nth node and not n-1th node from back)


 
 
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {

//        ListNode* front=head;
//        ListNode* back=head;

//        for(int i=1;i<=n;i++) {
//         front=front->next;
//        }

//        if(front==NULL){ //nth node from back is 1st node // first node remove
//         head=head->next;
//         back->next=NULL;
//         return head;
//        }
 
//  // ab dono saath bhadao
//         while(front->next!=NULL){
//             front=front->next;
//             back=back->next;
//         }

//        // back is at one node prev jise remove krna
//        ListNode* del=back->next;
//        back->next=del->next;
//        del->next=NULL;

//        return head;
//     }
// };