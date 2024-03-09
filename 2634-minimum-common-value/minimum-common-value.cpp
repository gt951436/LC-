class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int i = 0, j = 0;
        for(;i < n1 && j < n2;) {
            int x = nums1[i], y = nums2[j];
            if (x == y)
                return x;
            else if (x > y)
                j++;
            else
                i++;
        }
        return -1;
    }
};