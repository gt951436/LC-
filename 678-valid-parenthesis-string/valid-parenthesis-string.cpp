class Solution {
public:
    bool checkValidString(string s) {
        int openP = 0;
        int maxOpenP = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openP++;
                maxOpenP++;
            } else if (s[i] == ')') {
                openP--;
                maxOpenP--;
            } else if (s[i] == '*') {
                openP--;
                maxOpenP++;
            }
            if (openP < 0)
                openP = 0;
            if (maxOpenP < 0)
                return false;
        }
        if(openP==0)
        return true;
        return false;
    }
};