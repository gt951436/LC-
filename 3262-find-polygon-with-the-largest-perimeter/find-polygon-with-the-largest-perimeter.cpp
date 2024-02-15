class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long int sum = 0;
        for(int i=0;i<n;++i){
            sum+=nums[i];
        }
        sort(nums.begin(),nums.end(),greater<>());
        long long int maxPeri= -1;
        for(int i=0;i<n;++i){
            if(sum-nums[i]>nums[i]){
                maxPeri = max(sum,maxPeri);
                break;
            }
            else{
                sum-=nums[i];
            }
        }
        return maxPeri;
    }
};