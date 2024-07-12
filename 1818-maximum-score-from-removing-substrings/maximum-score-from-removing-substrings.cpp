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
    int removeSub(string& s, string sub, int pts) {
        // pts-->x/y AND sub.size()=2 (given)
        string temp;
        int subRemPoints = 0; // points after removal of substring
        for (char ch : s) {
            if (!temp.empty() &&
                (temp.back() == sub.front() && ch == sub.back())) {
                temp.pop_back();
                subRemPoints += pts;
            } else {
                temp.push_back(ch);
            }
        }
        s = temp; // bachaa hua string after removing sub
        return subRemPoints;
    }
};