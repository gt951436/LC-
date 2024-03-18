class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != ']') {
                stk.push(string(1, s[i]));
            } else {
                string sbs = "";
                while (stk.top() != "[") {
                    sbs = stk.top() + sbs;
                    stk.pop();
                }
                stk.pop();

                string k = "";
                while (!stk.empty() &&
                       isdigit(stk.top()[0])) {
                    k = stk.top() + k;
                    stk.pop();
                }

                int rpt = stoi(k);
                string res = "";
                for (int j = 0; j < rpt; ++j) {
                    res += sbs;
                }
                stk.push(res);
            }
        }

        string ans = "";
        while (!stk.empty()) {
            ans = stk.top() + ans;
            stk.pop();
        }

        return ans;
    }
};