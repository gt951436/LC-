class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> aCnt(n, 0);
        vector<int> bCnt(n, 0);
        int cntB = 0;
        for (int i = 0; i < n; i++) {
            bCnt[i] = cntB;
            if (s[i] == 'b')
                cntB++;
        }
        int cntA = 0;
        for (int i = n - 1; i >= 0; i--) {
            aCnt[i] = cntA;
            if (s[i] == 'a')
                cntA++;
        }
        int minDltCnt = n;
        for (int i = 0; i < n; i++) {
            minDltCnt = min(minDltCnt, aCnt[i] + bCnt[i]);
        }
        return minDltCnt;
    }
};