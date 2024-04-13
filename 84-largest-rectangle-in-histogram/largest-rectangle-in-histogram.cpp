class Solution {
public:
    int largestRectangleArea(vector<int>& ht) {
        int n = ht.size();
        int max_area = 0;

        vector<int> left_limit(n), right_limit(n);
        stack<int> stk;

        for (int i = 0; i < n; ++i) {
            if (stk.empty()) {
                left_limit[i] = 0;
                stk.push(i);
            } else {
                while (!stk.empty() && ht[i] <= ht[stk.top()]) {
                    stk.pop();
                }
                if (stk.empty())
                    left_limit[i] = 0;
                else
                    left_limit[i] = stk.top() + 1;
                stk.push(i);
            }
        }
        while (!stk.empty()) {
            stk.pop();
        }
        for (int i = n - 1; i >= 0; --i) {
            if (stk.empty()) {
                right_limit[i] = n - 1;
                stk.push(i);
            } else {
                while (!stk.empty() && ht[i] <= ht[stk.top()]) {
                    stk.pop();
                }
                if (stk.empty())
                    right_limit[i] = n - 1;
                else
                    right_limit[i] = stk.top() - 1;
                stk.push(i);
            }
        }
        for (int i = 0; i < n; ++i)
            max_area =
                max(max_area, (right_limit[i] - left_limit[i] + 1) * ht[i]);
        return max_area;
    }
};