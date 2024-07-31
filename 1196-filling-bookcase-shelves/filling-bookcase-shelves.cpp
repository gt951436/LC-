class Solution {
public:
    int n;
    int W;
    int dp[1001][1001];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        memset(dp, -1, sizeof(dp));
        n = books.size();
        W = shelfWidth;
        int remW = shelfWidth;
        return solve(books, 0, remW, 0);
    }
    int solve(vector<vector<int>>& books, int i, int remW, int maxH) {
        if (i >= n) {
            return maxH;
        }
        if (dp[i][remW] != -1) {
            return dp[i][remW];
        }
        int w = books[i][0];
        int h = books[i][1];
        int keep = INT_MAX;
        int skip = INT_MAX;
        // keep
        if (w <= remW) {
            keep = solve(books, i + 1, remW - w, max(maxH, h));
        }
        // skip and put in next shelf
        skip = maxH + solve(books, i + 1, W - w, h);
        return dp[i][remW]=min(keep, skip);
    }
};