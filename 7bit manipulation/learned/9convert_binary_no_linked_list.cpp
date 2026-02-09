//lc 1290


//m1

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int cnt=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            temp=temp->next;
            cnt++;
        }

        int idx=cnt-1;
        int value=0;
        temp=head;
        while(temp!=NULL){
            value+=pow(2,idx)*temp->val;
            idx--;
            temp=temp->next;
        }
        return value;
    }
};


//m2 bit manipulation


class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int value=0;
        ListNode* temp=head;
        while(temp!=NULL) {
            value=value<<1;
            value=value|temp->val;
            temp=temp->next;
        }

        return value;
    }
};