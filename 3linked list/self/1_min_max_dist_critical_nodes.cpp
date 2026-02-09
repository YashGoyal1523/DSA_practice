// lc 2058


// saari critical nodes ki positions ek vector m store krlege fir ans nikal lege

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
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       
//         vector<int>v; // will store positions of critical points
//         int pos=2; // second node se check krna shuru krege 
//          ListNode*prev=head;
//         ListNode*curr=head->next;
//         while(curr->next!=NULL){
//             if((curr->val<prev->val&&curr->val<curr->next->val) || (curr->val>prev->val&&curr->val>curr->next->val)){
//                 v.push_back(pos);
//             }
//             prev=curr;
//             curr=curr->next;
//             pos++;
//         }
//         // ab vector milgya h jisme sari positions stored h of critical points
//         if(v.size()<2) return {-1,-1};

//         // yaha h toh ans possible h

//         // max dist toh critical points ki lastpos-firstpos  hi hoga no doubt
//         int max=v[v.size()-1]-v[0];
//         // for min ... har consecutive pos ka diff dekhna pdega and min lena hoga
//         int mini=INT_MAX;
//         for(int i=0;i<v.size()-1;i++){
//             int diff=v[i+1]-v[i];
//             mini=min(mini,diff);
//         }
//         return {mini,max};
//     }
// };