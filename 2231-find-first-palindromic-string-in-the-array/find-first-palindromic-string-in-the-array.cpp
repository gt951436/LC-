class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();++i){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
    bool isPalindrome(string s){
        int n = s.length();
       int i=0;
       int j=n-1;
       while(i<j){
           if(s[i]!=s[j]){
              return false;
           }
           ++i;
           --j;
       }
        return true;
    }
};