class Solution {
public:
    string maximumOddBinaryNumber(string s) 
    {
        int ones=0,zeroes=0;
        for(int i=0;i<s.length();++i){
            if(s[i]=='1')
            ones++;
        }
        zeroes = s.length() - ones;
        for(int i=0;i<(ones-1);++i)
        {
            s[i]='1';
        }
        for(int i=(ones-1);i<s.length()-1;++i){
            s[i]='0';
        }
        s[s.length()-1]='1';

        return s;
    }
};