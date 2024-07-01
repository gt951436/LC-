class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int consOdd = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 1) {
                consOdd++;
            } else {
                consOdd = 0;
            }
            if (consOdd == 3) {
                return true;
            }
        }
        return false;
    }
};