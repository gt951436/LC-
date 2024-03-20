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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l = NULL;
        ListNode* r = list1;
        for (int i = 0; i < b + 1; ++i) {
            if (i == a - 1) {
                l = r;
            }
            r = r->next; // r is at b.
        }
        l->next = list2;
        ListNode* tp = list2;
        while (tp != NULL && tp->next != NULL) {
            tp = tp->next;
        }
        tp->next = r; // list 2 ke end ko r(or b) se link kra
        return list1;
    }
};