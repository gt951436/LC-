class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> final;
        double ans = 0.0;
        for (int i = 0; i < nums1.size(); ++i) {
            final.push_back(nums1[i]);
        }
        for (int i = 0; i < nums2.size(); ++i) {
            final.push_back(nums2[i]);
        }
        sort(final.begin(), final.end());
        if (final.size() % 2) {
            int mid = 0 + (final.size() - 1) / 2;
            ans+=final[mid];
            return ans;
        }
        int mid = 0 + (final.size() - 1) / 2;
        int nxtMid = mid + 1;
        double avg = (final[mid] + final[nxtMid]) / 2.0;
        return avg;
    }
};