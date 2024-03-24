class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // HARE AND TORTOISE ALGORITHM
        int slow = nums[0];
        int fast = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) { //cycle detection
            slow = nums[slow];
            fast = nums[nums[fast]];
        } 
        slow = nums[0]; 

        while(slow!=fast){  // l1+l2 = n*k ===> l1 = n*k - l2
            slow=nums[slow];
            fast = nums[fast];
        }
        return slow; // or fast
    }
};