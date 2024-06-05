#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> ComCnt(26), CurrCnt(26);
        int n = words.size();

        for (char& ch : words[0]) {
            ComCnt[ch - 'a']++;
        }
        for (int i = 1; i < n; ++i) {
            for (int k = 0; k < 26; ++k) {
                CurrCnt[k] = 0;
            }
            for (char& ch : words[i]) {
                CurrCnt[ch - 'a']++;
            }
            for (int j = 0; j < 26; ++j) {
                ComCnt[j] = min(ComCnt[j], CurrCnt[j]);
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (ComCnt[i]--) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};