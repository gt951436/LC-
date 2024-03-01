class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        string ans = "";
        ans += '1';
        int ones = -1, zeroes = 0;
        for (auto it : s) {
            ones += (it == '1');
            zeroes += (it == '0');
        }
        for (int i = 1; i <= zeroes; ++i) {
            ans += '0';
        }
        for (int i = 1; i <= ones; ++i) {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};