class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            ans += countLargerLeft(i, rating) * countSmallerRight(i, rating);
            ans += countSmallerLeft(i, rating) * countLargerRight(i, rating);
        }
        return ans;
    }

private:
    int countSmallerLeft(int idx, vector<int>& rating) {
        int count = 0;
        for (int i = 0; i < idx; ++i) {
            if (rating[i] < rating[idx]) {
                count++;
            }
        }
        return count;
    }

    int countLargerLeft(int idx, vector<int>& rating) {
        int count = 0;
        for (int i = 0; i < idx; ++i) {
            if (rating[i] > rating[idx]) {
                count++;
            }
        }
        return count;
    }

    int countSmallerRight(int idx, vector<int>& rating) {
        int count = 0;
        for (int i = idx + 1; i < rating.size(); ++i) {
            if (rating[i] < rating[idx]) {
                count++;
            }
        }
        return count;
    }

    int countLargerRight(int idx, vector<int>& rating) {
        int count = 0;
        for (int i = idx + 1; i < rating.size(); ++i) {
            if (rating[i] > rating[idx]) {
                count++;
            }
        }
        return count;
    }
};
