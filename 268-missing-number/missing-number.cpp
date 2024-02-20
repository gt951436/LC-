class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long int sum=0;
        int n = nums.size();
        for(int i=0;i<nums.size();++i){
         sum+=nums[i];
        }
        long long int S = ((n*(n+1))/2);
        return S-sum;
    }
};