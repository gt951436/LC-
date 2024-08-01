#include <bits/stdc++.h>
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (int i = 0; i < details.size(); ++i) {
            string age;
            age = details[i][11];
            age += details[i][12];
            if(age>"60"){
                ++cnt;
            }
        }
        return cnt;
    }
};