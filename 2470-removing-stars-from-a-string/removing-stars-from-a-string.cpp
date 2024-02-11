class Solution {
public:
    string removeStars(string s) {
        stack<char> stk;
        string ans = "";
        for (auto it : s) {
            if (it != '*')
                stk.push(it);
            else if (it == '*')
                stk.pop();
        }
       while(!stk.empty()){
           char ch = stk.top();
           stk.pop();
           ans+=ch;
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};