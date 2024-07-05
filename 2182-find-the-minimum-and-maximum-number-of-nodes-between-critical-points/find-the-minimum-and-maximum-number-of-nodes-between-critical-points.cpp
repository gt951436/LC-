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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> nodeValues;
        while (head != NULL) {
            nodeValues.push_back(head->val);
            head = head->next;
        }
        if (nodeValues.size() < 3) {
            return {-1, -1};
        }
        vector<int> idx;
        for (int i = 1; i < nodeValues.size() - 1; ++i) {
            if ((nodeValues[i] > nodeValues[i - 1] && nodeValues[i] > nodeValues[i + 1]) ||
                (nodeValues[i] < nodeValues[i - 1] && nodeValues[i] < nodeValues[i + 1])) {
                idx.push_back(i);
            }
        }
        if (idx.size() < 2) {
            return {-1, -1};
        }
        int minDist = INT_MAX;
        int maxDist = idx.back() - idx.front();
        for (int i = 1; i < idx.size(); ++i) {
            minDist = min(minDist, idx[i] - idx[i - 1]);
        }
        return {minDist, maxDist};
    }
};