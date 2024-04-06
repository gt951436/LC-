class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openP = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                openP++;
            } else if (s[i] == ')') {
                if (openP == 0)
                    s[i] = '#';
                else
                    openP--;
            }
        }
        for (int i = s.length() - 1; i >= 0; --i) {
            if (openP > 0 && s[i] == '(') {
                s[i] = '#';
                --openP;
            }
        }
         string ans="";
        for(int i=0;i<s.length();++i){
            if(s[i]!='#')
            ans+=s[i];
        }
        return ans;
    }
};