class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        queue<int>positives,negatives;
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0){
                positives.push(nums[i]);
            }
            else{
                negatives.push(nums[i]);
            }
        }
        while(!positives.empty() || !negatives.empty()){
            ans.push_back(positives.front());
            ans.push_back(negatives.front());
            positives.pop();
            negatives.pop();
        }
        return ans;
    }
};