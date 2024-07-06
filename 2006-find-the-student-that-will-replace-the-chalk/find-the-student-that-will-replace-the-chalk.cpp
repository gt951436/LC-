class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (int i = 0; i < chalk.size(); ++i) {
            sum += chalk[i];
        }
        k = (long long)k % sum;
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i])
                return i;
            else
                k -= chalk[i];
        }
        return -1;
    }
};