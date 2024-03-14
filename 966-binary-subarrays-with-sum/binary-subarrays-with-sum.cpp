class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        map<int,int>mp;
        mp[0]=1;
        int pSum=0,cnt=0;
        for(int i=0;i<nums.size();++i){
         pSum+=nums[i];
         int r=pSum-k;
         cnt+=mp[r];
         mp[pSum]+=1;
        }
        return cnt;
    }
};