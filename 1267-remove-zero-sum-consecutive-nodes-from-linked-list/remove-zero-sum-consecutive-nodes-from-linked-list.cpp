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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mp;
        int ps = 0;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        mp[0] = dummyNode;
        while (head != NULL) {
            ps += head->val;
            if (mp.find(ps) != mp.end()) {
                // deletion karo
                ListNode* start = mp[ps];
                ListNode* temp = start;
                int curr_sum = ps;
                while (temp != head) {
                    temp = temp->next;
                    curr_sum += temp->val;
                    if (temp != head) {
                        mp.erase(curr_sum);
                    }
                }
                start->next = head->next;
            } else {
                mp[ps] = head;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};