class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        vector<int> fq;
        for (int& it : arr) {
            mp[it]++;
        }
        for (auto p : mp) {
            fq.push_back(p.second);
        }
        sort(fq.begin(), fq.end());
        int cnt = 0;
        for (int& it : fq) {
            if (k >= it) {
                k -= it;
                cnt++;
            } 
            else {
                break;
            }
        }

        return (fq.size() - cnt);
    }
};