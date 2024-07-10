class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> stk;
        for (int i = 0; i < logs.size(); ++i) {
            if (logs[i] == "../") {
                if (!stk.empty()) {
                    stk.pop();
                }
            } else if (logs[i] != "./")
                stk.push(logs[i]);
        }
        return stk.size();
    }
};