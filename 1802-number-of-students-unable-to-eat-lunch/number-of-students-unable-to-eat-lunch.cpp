#include <bits/stdc++.h>
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) { 
        int remain = sandwiches.size();
        vector<int> prefer(2);
        for (int x : students) {
            prefer[x]++;
        }
        for (int y : sandwiches) {
            if (prefer[y] == 0)
                break;
            if (remain == 0)
                break;
            --prefer[y];
            --remain;
        }
        return remain;
    }
};