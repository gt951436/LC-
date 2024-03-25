class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<n;++i){
            int val = abs(nums[i]);
            int idx = val -1;
            if(nums[idx]<0){
                ans.push_back(val);
            }
            else{
                nums[idx]*=-1;
            }
        }
        return ans;
    }
};