class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_total = 0;
        for (int x : nums) {
            xor_total ^= x;
        }
        unsigned int ryt_set_bit = xor_total & -(unsigned int)xor_total;
        vector<int>ans(2,0);
        for(int it:nums){
            if((ryt_set_bit & it)==0){
                ans[0]^=it;
            }
            else{
                ans[1]^=it;
            }
        }
        return ans;
    }
};