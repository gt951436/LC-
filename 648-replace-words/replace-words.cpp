class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> st(dict.begin(), dict.end());
        string ans, word;
        bool f=0;
        for (char c: sentence) {
            if (c!= ' ') {
                word+=c;
                if (!f && st.count(word)) {
                    ans+=word;
                    f=1;
                }
            } 
            else {
                if (!f) ans+=word;
                ans+=' ';
                word="";
                f=0;
            }
        }
        if (!f)
            ans+=word;
        return ans;
    }
};