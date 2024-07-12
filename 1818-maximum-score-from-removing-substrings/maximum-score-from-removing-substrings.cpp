class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int totPts = 0;
        if (x > y) { // remove "ab" before "ba"
            totPts += removeSub(s, "ab", x);
            totPts += removeSub(s, "ba", y);
        } else { // remove "ba" before "ab"
            totPts += removeSub(s, "ba", y);
            totPts += removeSub(s, "ab", x);
        }
        return totPts;
    }
    int removeSub(string& s, string sub,
                  int pts) { // pts-->x/y AND sub.size()=2
        stack<char> stk;
        int subRemPoints = 0; // points after removal of substring
        for (char ch : s) {
            if (!stk.empty() &&
                (stk.top() == sub.front() && ch == sub.back())) {
                stk.pop();
                subRemPoints += pts;
            } else {
                stk.push(ch);
            }
        }
        // s = "";
        s.clear();
        while (!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end()); // bachaa hua string after removing sub
        return subRemPoints;
    }
};