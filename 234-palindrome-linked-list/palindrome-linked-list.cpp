class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode* fast = head;
        ListNode* slow = head;

        // Find the middle of the linked list
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // Reverse the second half of the linked list
        ListNode* tail = reverse(slow->next);

        // Compare the two halves
        while (tail != nullptr) {
            if (tail->val != head->val) {
                return false;
            } else {
                tail = tail->next;
                head = head->next;
            }
        }
        return true;
    }

private:
    ListNode* reverse(ListNode* curr) {
        ListNode* prev = nullptr;
        ListNode* nextNode = nullptr;
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
};
