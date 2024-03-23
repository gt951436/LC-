class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* fast = head;
        ListNode* slow = head;
       // ListNode* pr = nullptr; // to divide list at middle
       
        // Find the middle of the linked list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Reverse the second half of the linked list
        slow = reverse(slow->next);

        // Compare the two halves
        while (slow != nullptr && head != nullptr) {
            if (slow->val != head->val) {
                return false;
            } else {
                slow = slow->next;
                head = head->next;
            }
        }
        return true;
    }

private:
    ListNode* reverse(ListNode* curr) {
        ListNode* prev = nullptr;
        ListNode* nextNode = curr;
        while (curr != nullptr) {
            nextNode = nextNode->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
