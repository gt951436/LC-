class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long long int sum = accumulate(nums.begin(),nums.end(),0LL);
        long long int S = (n*1LL*(n+1)*1LL)/2;
        return S-sum;
    }
};