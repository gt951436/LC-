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
        for(int i=0;i < n/2;++i){
            if(s[i]!=s[n-1-i]){
                return false;
            }
        }
        return true;
    }
};