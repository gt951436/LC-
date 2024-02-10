class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        vector<int>v;
        for(auto it:s){
            v.push_back(it);
        }
        nums=v;
        return nums.size();
    }
};