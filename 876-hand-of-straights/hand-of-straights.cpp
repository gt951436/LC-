class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) {
            return false;
        }
        map<int, int> freq_mp;
        for (int it : hand) {
            freq_mp[it]++;
        }
        sort(hand.begin(), hand.end());
        for (int it : hand) {
            if (freq_mp[it] > 0) {
                for (int i = it; i < it + groupSize; ++i) {
                    --freq_mp[i];
                    if (freq_mp[i] < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};