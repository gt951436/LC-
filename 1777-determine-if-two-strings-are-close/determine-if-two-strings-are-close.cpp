class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        set<char> s1, s2;
        for (char it : word1) {
            v1[it - 'a']++;
            s1.insert(it);
        }
        for (char it : word2) {
            v2[it - 'a']++;
            s2.insert(it);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return (v1 == v2 && s1 == s2);
    }
};