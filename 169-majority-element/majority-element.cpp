class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        bool flag =false;
        int x=0;
        for(auto it:mp){
            if(it.second>(nums.size()/2)){
           flag = true;
           x = it.first;
           break;}
        }
       if(flag)
       return x;
       else
       return -1;
    }
};