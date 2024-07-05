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
        // 3 se kam nodes hone par critical points nahi honge!
        if (nodeValues.size() < 3) {
            return {-1, -1};
        }
        vector<int> idx;
        // indexes of critical points store karao in idx.
        for (int i = 1; i < nodeValues.size() - 1; ++i) {
            if ((nodeValues[i] > nodeValues[i - 1] && nodeValues[i] > nodeValues[i + 1]) ||
                (nodeValues[i] < nodeValues[i - 1] && nodeValues[i] < nodeValues[i + 1])) {
                idx.push_back(i);
            }
        }
        // agar critical points 2 se kam hue..yaani 1 ya 0..then
        //return [-1,-1].
        if (idx.size() < 2) {
            return {-1, -1};
        }
        int minDist = INT_MAX;
        // maxDist between any two critical points to 
        //last wale index and first wale index ka distance rahega.
        int maxDist = idx.back() - idx.front();
        for (int i = 1; i < idx.size(); ++i) {
            minDist = min(minDist, idx[i] - idx[i - 1]);
        }
        return {minDist, maxDist};
    }
};