class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> seq;
        for (int i = 0; i < n; ++i) {
            seq.push_back(i + 1);
        }
        int startRemoval = 0;
        while (seq.size() > 1) {
            int removalIdx = (startRemoval + k - 1) % seq.size();
            seq.erase(seq.begin() + removalIdx);
            startRemoval = removalIdx;
        }
        return seq.front();
    }
};