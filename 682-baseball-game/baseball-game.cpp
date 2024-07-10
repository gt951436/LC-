class Solution {
public:
    int calPoints(vector<string>& operations) {
        int totRecord = 0;
        stack<int> stk;
        for (int i = 0; i < operations.size(); ++i) {
            if (operations[i] != "C" && operations[i] != "D" && operations[i] != "+") {
                stk.push(stoi(operations[i]));
            } else if (operations[i] == "C") {
                stk.pop();
            } else if (operations[i] == "D") {
                stk.push(stk.top() * 2);
            } else if (operations[i] == "+") {
                int tp1 = stk.top();
                stk.pop();
                int tp2 = stk.top();
                stk.push(tp1);
                stk.push(tp1 + tp2);
            }
        }
        while (!stk.empty()) {
            totRecord += stk.top();
            stk.pop();
        }
        return totRecord;
    }
};
