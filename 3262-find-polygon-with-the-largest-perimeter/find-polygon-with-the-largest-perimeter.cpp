class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long int sum = accumulate(nums.begin(),nums.end(),0LL);
        priority_queue<int>pq(nums.begin(),nums.end());
        while (pq.size() >= 3) {
            auto tp = pq.top();
            if (sum - tp > tp) 
            return sum;
            pq.pop();
            sum -= tp; 
        }
        return -1;
    }
};