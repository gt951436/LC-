class Solution {
public:
    bool isBad(string& s, int i) {
        if ((s[i] >= 'a' && s[i] <= 'z' && s[i] == s[i+1] + 32) ||
            (s[i] >= 'A' && s[i] <= 'Z' && s[i] == s[i+1] - 32)) {
            return true;
        }
        return false;
    }
    string makeGood(string s) {
        string temp = s;
        bool f = 0;
        while (f == 0 && temp != "") {
            f = 1;
            for (int i = 0; i < temp.size() - 1; ++i) {
                if (isBad(temp, i)) {
                    temp.erase(i, 2);
                    f = 0;
                    break;
                }
            }
        }
        return temp;
    }
};