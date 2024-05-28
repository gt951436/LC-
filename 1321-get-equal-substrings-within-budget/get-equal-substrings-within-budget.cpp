class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();

        int maxLen = 0;
        int st = 0;
        int currCost = 0;

        for (int i = 0; i < n; i++) {
            currCost += abs(s[i] - t[i]);
            while (currCost > maxCost) {
                currCost -= abs(s[st] - t[st]);
                st++;
            }
            maxLen = max(maxLen, i - st + 1);
        }
        return maxLen;
    }
};