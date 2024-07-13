class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        int n = healths.size();
        map<int, pair<int, char>> robot;
        for (int i = 0; i < n; ++i) {
            robot[positions[i]] = {healths[i], directions[i]};
        }
        stack<pair<int, int>> stk; // store {position, health} of robots moving 
        map<int, int> remHealths; // store surviving robots health
        
        for (auto it : robot) {
            int p = it.first;
            int h = it.second.first;
            char d = it.second.second;
            if (d == 'R') {
                stk.push({p, h});
            } else {
                while (!stk.empty() && h > 0) {
                    auto it = stk.top();
                    stk.pop();
                    if (it.second > h) {
                        it.second--;
                        if (it.second > 0) {
                            stk.push({it.first, it.second});
                        }
                        h = 0;
                    } else if (it.second < h) {
                        h--;
                    } else {
                        h = 0;
                    }
                }
                if (h > 0) {
                    remHealths[p] = h;
                }
            }
        }  
        // Add remaining moving robots to remHealths
        while (!stk.empty()) {
            auto it = stk.top();
            stk.pop();
            remHealths[it.first] = it.second;
        }
        //surviving robots health in og order
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (remHealths.count(positions[i])) {
                ans.push_back(remHealths[positions[i]]);
            }
        }
        return ans;
    }
};