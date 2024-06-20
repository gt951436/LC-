class Solution {
public: // Binary Search on answer..distance is ans so BS on distance
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int ans = 0;

        int least_gap = 1;
        int max_gap = ceil(position[n - 1] / (m - 1 * 1.0));
        while (least_gap <= max_gap) {
            int mid = least_gap + (max_gap - least_gap) / 2;
            if (canPlaceBalls(position, mid, m)) {
                ans = mid;
                least_gap = mid + 1;
            } else {
                max_gap = mid - 1;
            }
        }
        return ans;
    }
    bool canPlaceBalls(vector<int>& position, int gap, int m) {
        int prevBallPosition = position[0];
        int BallCnt = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (BallCnt < m) {
                int currBallPos = position[i];
                if (currBallPos - prevBallPosition >= gap) {
                    prevBallPosition = currBallPos;
                    BallCnt++;
                }
            }
        }
        if (BallCnt == m)
            return true;
        return false;
    }
};