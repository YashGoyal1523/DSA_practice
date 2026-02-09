//lc 237
To delete a node from a linked list, we typically redirect the previous node's next pointer to the subsequent node of the one being deleted. For example, to remove node 3 from a linked list, we would adjust node 2's next pointer to reference node 4 directly. This effectively excludes node 3 from the traversal path, rendering it inaccessible during iteration, and thus, it is considered deleted.
However, a challenge arises when we cannot access the previous node, as is the case in this specific problem. Since we can only traverse forward from the node to be deleted, the conventional deletion method is not feasible.
Approach: Data Overwriting
 By comparing the original linked list with the desired outcome post-deletion, we notice that the nodes following the target node appear to shift one position to the left.
 We can replicate this effect by copying the data from each subsequent node into its predecessor, starting from the node to be deleted, and then unlinking the last node.

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
    void deleteNode(ListNode* node) {
        while(node->next->next!=NULL){
            node->val=node->next->val;
            node=node->next;
        }
         node->val=node->next->val;
        node->next=NULL;

    }
};