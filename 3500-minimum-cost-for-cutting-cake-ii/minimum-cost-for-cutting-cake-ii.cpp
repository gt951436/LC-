class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut,
                          vector<int>& verticalCut) {

        int i = 0, j = 0, hp = 1, vp = 1;
        long long totCost = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());

        while (i < horizontalCut.size() && j < verticalCut.size()) {
            if (horizontalCut[i] < verticalCut[j]) {
                totCost += verticalCut[j] * hp;
                ++vp;
                ++j;
            } else {
                totCost += horizontalCut[i] * vp;
                ++hp;
                ++i;
            }
        }
        while (i < horizontalCut.size()) {
            totCost += horizontalCut[i] * vp;
            ++i;
        }
        while (j < verticalCut.size()) {
            totCost += verticalCut[j] * hp;
            ++j;
        }
        return totCost;
    }
};