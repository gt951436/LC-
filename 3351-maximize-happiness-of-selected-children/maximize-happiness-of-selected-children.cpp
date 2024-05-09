class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        int cnt=0;
        long long int ans=0;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int t=n-1;
        while(k>0 && t>=0){
            ans+=max(0,arr[t]-cnt);
            ++cnt;
            --k;
            --t;
        }
        return ans;
    }
};