class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele=0,cnt=0;
        for (auto it : nums) {
            if(cnt==0)
            ele=it;
            if(it==ele)
            cnt++;
            else
            cnt--;
        }
        return ele;
    }
};