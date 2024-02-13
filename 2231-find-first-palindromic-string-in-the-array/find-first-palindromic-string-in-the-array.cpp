class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto it:words) {
            if (isPal(it)) {
                return it;
            }
        }
        return "";
    }
    bool isPal(string s) {
        int n = s.size();
        for (int i =0; i<n/2; i++) {
            if (s[i] != s[n-i-1])
                return false;
        }
        return true;
    }
};