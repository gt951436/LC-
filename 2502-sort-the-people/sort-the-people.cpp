class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> sorted;
        for (int i = 0; i < names.size(); ++i) {
            sorted.push_back({heights[i], names[i]});
        }
        sort(sorted.begin(), sorted.end(),
             [](const pair<int, string>& a, const pair<int, string>& b) {
                 return a.first > b.first;
             });
        for (int i = 0; i < sorted.size(); ++i) {
            names[i] = sorted[i].second;
        }
        return names;
    }
};