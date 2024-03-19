class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto &it: spells){
            int l = 0;
            int r = m-1;
            while(l<=r){
                int mid = (l+r)/2;
                long long x = potions[mid];
                if(it*x<success){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            ans.push_back(m-r-1);
        }
        return ans;
    }
};