class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> sf; // string freq
        for (auto str : arr) {
            sf[str]++;
        }
        int i = 0;
        for (auto it : arr) { // arr preserve the order
            if (sf[it] == 1) {
                ++i;
            }
            if (i == k) {
                return it;
            }
        }
        return "";
    }
};