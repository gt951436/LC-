class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        bitset<1001> bs1, bs2;
        for (int it : nums1) {
            bs1.set(it);
        }
        for(int it:nums2){
            if(bs1.test(it))
            bs2.set(it);
        }
        for(int i=0;i<bs2.size();++i){
            if(bs2.test(i))
            ans.push_back(i);
        }
        return ans;
    }
};