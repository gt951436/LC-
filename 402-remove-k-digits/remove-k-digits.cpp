class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        string ans;

        if (num.length() == k)
            return "0";

        for (int i = 0; i < num.size(); ++i) {
            while (!stk.empty() && k > 0 && num[i] < stk.back()) {
                stk.pop_back();
                --k;
            }
            stk.push_back(num[i]);
        }

        while (k > 0 && !stk.empty()) {
            stk.pop_back();
            --k;
        }

        for (char it : stk) {
            if (it == '0' && ans.empty())
                continue;
            ans += it;
        }
        if (ans.empty())
            return "0";

        return ans;
    }
};