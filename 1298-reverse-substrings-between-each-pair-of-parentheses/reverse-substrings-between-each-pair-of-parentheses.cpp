class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk; // openingParanthesesIdx ->stk
        string ans = "";
        for (auto it : s) {
            if (it == '(') {
                stk.push(ans.length());
            } else if (it == ')') {
                int startIdx = stk.top();
                stk.pop();
                reverse(ans.begin() + startIdx,ans.end());
            } else {
                ans += it;
            }
        }
        return ans;
    }
};