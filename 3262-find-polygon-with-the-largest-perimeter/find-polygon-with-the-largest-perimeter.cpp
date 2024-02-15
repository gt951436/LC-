class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        sort(nums.begin(), nums.end(), greater<>());
        long long int maxPeri = -1;
        for (auto it : nums) {
            if (sum - it > it) {
                maxPeri = sum;
                break;
            } else {
                sum -= it;
            }
        }
        return maxPeri;
    }
};