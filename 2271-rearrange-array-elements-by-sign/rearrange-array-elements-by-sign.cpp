class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        stack<int>pos,neg;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]>0){
                pos.push(nums[i]);
            }
            else{
                neg.push(nums[i]);
            }
        }
        while(!pos.empty() || !neg.empty()){
            ans.push_back(pos.top());
            ans.push_back(neg.top());
            pos.pop();
            neg.pop();
        }
        return ans;
    }
};