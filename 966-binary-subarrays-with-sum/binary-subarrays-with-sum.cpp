class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        map<int, int> mp;
        mp[0] = 1;
        int pSum = 0;
        int cnt = 0;
        for (auto it : nums) {
            pSum += it;
            int r = pSum - goal;
            if (mp.find(r) != mp.end())
                cnt += mp[r];
            mp[pSum]++;
        }
        return cnt;
    }
};