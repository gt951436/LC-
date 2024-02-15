class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        priority_queue<int>pq(nums.begin(),nums.end());
        while (pq.size() > 2) {
            auto tp = pq.top();
            if (sum - tp > tp) 
            return sum;
            pq.pop();
            sum -= tp; 
        }
        return -1;
    }
};