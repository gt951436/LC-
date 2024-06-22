class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>ans;
        
        int i,j;
        for(i=0;i<n;i++)
        {
            vector<int>v;
            int cnt=0;
            for(j=i;j<n;j++)
            {
                v.push_back(nums[j]);
                if(nums[j]%p==0)
                    ++cnt;
                if(cnt>k)
                    break;
                ans.insert(v);   
            }
        }
        return ans.size();
    }
//     int atmost(int k,int p,vector<int>& nums){
//         int s=0,e=0;
//         int ans=0;
//         for(e=0;e<nums.size();++e){
//            if (nums[e] % p == 0) {
//                 k -= 1;
//             }
//             while (k < 0) {
//                 if (nums[s] % p == 0)
//                     k++;
//                 s++;
//             }
//             ans += (e - s + 1);
//         }
//         return ans;
//     }
};