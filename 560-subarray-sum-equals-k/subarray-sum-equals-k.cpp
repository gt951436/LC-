class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int pSum=0;
        int cnt=0;
        for(int i=0;i<n;++i){
            pSum+=nums[i];
            int rem = pSum-k;
            if(mp.find(rem)!=mp.end()){
            cnt+=mp[rem];
            mp[pSum]+=1;
            }
            else{
                mp[pSum]+=1;
            }
        }
        return cnt;
    }
};