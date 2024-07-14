class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push(map<string, int>());

        int i = 0;
        while (i < formula.length()) {
            if (formula[i] == '(') {
                stk.push(map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                map<string, int> currMap = stk.top();
                stk.pop();
                i++;
             //-------------------------------------------
                string atomCnt;
                while (i < formula.length() && isdigit(formula[i])) {
                    atomCnt += formula[i];
                    i++;
                }
                int cnt = atomCnt.empty() ? 1 : stoi(atomCnt);
             //---------------------------------------------
                //merge currMap in stk.top()
                for (auto& [atom, count] : currMap) {
                    stk.top()[atom] += count * cnt;
                }
            } else {
                string currAtom;
                currAtom += formula[i];
                ++i;
                while (i < formula.length() && islower(formula[i])) {
                    currAtom += formula[i];
                    ++i;
                }
                string atomCnt;
                while (i < formula.length() && isdigit(formula[i])) {
                    atomCnt += formula[i];
                    ++i;
                }
                int cnt = atomCnt.empty() ? 1 : stoi(atomCnt);
                stk.top()[currAtom] += cnt;
            }
        }
        string ans;
        for (const auto& it : stk.top()) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;      
    }
};