class Solution {
private:
    vector<pair<int, int>> vcx;
    int mappingVal(int num, vector<int>& mapping) {
        if (num == 0) 
        return mapping[0]; // special case
        int res = 0, pos = 1;
        while (num > 0) {
            int rem = num % 10;
            res += mapping[rem] * pos;
            pos *= 10;
            num /= 10;
        }
        return res;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            int mpVal = mappingVal(nums[i], mapping);
            vcx.push_back({mpVal, i});
        }
        sort(vcx.begin(), vcx.end());
        vector<int> ans;
        for (auto it : vcx) {
            ans.push_back(nums[it.second]);
        }
        nums = ans;
        return nums;
    }
};