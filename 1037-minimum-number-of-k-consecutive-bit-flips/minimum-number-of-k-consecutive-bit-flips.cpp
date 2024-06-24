class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int currWinFlips = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i - k >= 0 && nums[i - k] == 2) {
                currWinFlips -= 1;
            }
            if ((nums[i] + currWinFlips) % 2 == 0) {
                if (i + k > nums.size())
                    return -1;
                ans+=1;
                currWinFlips+=1;
                nums[i]=2;
            }
        }
        return ans;
    }
};