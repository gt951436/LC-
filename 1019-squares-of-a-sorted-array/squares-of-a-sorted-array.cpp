class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            nums[i]*=nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
    int square(int n){
        if(n%2==0){
            return ((n>>2)*(n>>2))<<2;
        }
        else{
            return (((n>>2)*(n>>2))<<2) + ((n>>2)<<2) + 1; 
        }
    }
};