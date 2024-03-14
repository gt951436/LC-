class Solution {

public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> mpp;

        int Psum = 0;
        int cnt = 0;

        for(auto it:nums)
        {
            Psum+=it;
            if(Psum==goal) cnt++;
            if(mpp.find(Psum-goal)!=mpp.end())
            {
                cnt+=mpp[Psum-goal];
            }
           mpp[Psum]++;

        }
        return cnt;
    }
};