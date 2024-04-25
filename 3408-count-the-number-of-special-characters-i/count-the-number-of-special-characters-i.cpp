class Solution {
public:
    int numberOfSpecialChars(string word) 
    {
        int res=0;
        unordered_set<char> st(begin(word),end(word));
        unordered_set<char> s;
        for(int i=0;i<word.size();i++)
        {
            if(isupper(word[i]))
            {
                if(st.count(tolower(word[i])))
                {
                    s.insert(word[i]);
                }
            }
        }
        return s.size();
    }
};