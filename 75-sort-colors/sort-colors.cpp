class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0, ones = 0, twos = 0;
        for (int it : nums) {
            if (it == 0)
                zeroes++;
            else if (it == 1)
                ones++;
            else if (it == 2)
                twos++;
        }
        int i = 0;
        while (zeroes && i < nums.size()) {
            nums[i] = 0;
            zeroes -= 1;
            i++;
        }
        int j = i;
        while (ones && j < nums.size()) {
            nums[j] = 1;
            ones -= 1;
            j++;
        }
        int k = j;
        while (twos && k < nums.size()) {
            nums[k] = 2;
            twos -= 1;
            ++k;
        }
    }
};