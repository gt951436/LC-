class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        unordered_set<int> unique;
        vector<int>ans;
        int i = 0, j = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                unique.insert(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else
                i++;
        }
        for(auto it:unique){
            ans.push_back(it);
        }
        return ans;
    }
};