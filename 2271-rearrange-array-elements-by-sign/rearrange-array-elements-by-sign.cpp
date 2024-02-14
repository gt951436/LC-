class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>v;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                v.push_back(nums[i]);
            }
        }
         for(int i=0;i<nums.size();++i){
            if(nums[i]<0){
                v.push_back(nums[i]);
            }
        }
        int n = v.size();
        for(int i=0;i<n/2;++i){
            ans.push_back(v[i]);
            ans.push_back(v[(n/2) + i]);
        }
        return ans;
    }
};