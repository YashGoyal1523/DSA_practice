//lc 24

// https://youtu.be/8yLiGS4ntHw?si=Sw8xx4oWH654ioSe
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* solve(ListNode* head){

        // a->b->c-> ...
        // a : head
        //b : head->next
        //c : head->next->next

        if(head==NULL||head->next==NULL) return head;

        ListNode* temp=head->next;
        head->next=solve(head->next->next);
        temp->next=head;

        return temp;
    }

    ListNode* swapPairs(ListNode* head) {
       ListNode* ans=solve(head);
       return ans;
    }
};