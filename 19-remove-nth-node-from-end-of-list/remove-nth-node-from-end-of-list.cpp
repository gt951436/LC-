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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int len = 0;
        ListNode *temp = head;
      //Traverse the linked list to find its length
        while(temp != nullptr) {
            len++;
            temp = temp->next;
        }
        // Reset temp to the head of the list
        temp = head;
        ListNode* prev;
        int pos = len - n;
        // Special case: If the node to be removed is the head itself
        if(pos == 0) return head->next;
        //Traverse the list again to reach the node just before the one to be removed
        for(int i = 0; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        //Update the pointers to remove the node
        prev->next = temp->next;
        //Delete the removed node
        delete temp; 
        return head;   
    }
};