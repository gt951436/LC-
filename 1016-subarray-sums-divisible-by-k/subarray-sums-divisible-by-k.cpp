class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        int prefixMod = 0, result = 0;
        vector<int> gp(k);
        gp[0] = 1;

        for (int num : nums) {
            prefixMod = (prefixMod + num % k + k) % k;
            result += gp[prefixMod];
            gp[prefixMod]++;
        }
        return result;
    }
};