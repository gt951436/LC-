class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans = 0, total = 0;
        for(int i = 0; i < customers.size(); i++) {
            total += (1 - grumpy[i]) * customers[i];
        }
        // in the window
        int all = 0, partial = 0;
        for(int i = 0; i < customers.size(); i++) {
            all += customers[i];
            partial += ((1 - grumpy[i]) * customers[i]);
            if(i + 1 >= minutes) {
                ans = max(ans, total - partial + all);
                int left = i - minutes + 1;
                all -= customers[left];
                partial -= ((1 - grumpy[left]) * customers[left]);
            }
        }
        return ans;
    }
};