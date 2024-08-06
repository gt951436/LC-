class Solution {
public:
    int minimumPushes(string word) {
        vector<int> f(26, 0);
        for (int i = 0; i < word.length(); ++i) {
            f[word[i] - 'a']++;
        }
        sort(f.begin(), f.end(), greater<int>());
        int timesCnt = 0;
        for (int i = 0; i < 26; ++i) {
            timesCnt += (f[i] * (i / 8 + 1));
        }
        return timesCnt;
    }
};