class Solution {
public:
    int minimumLength(string s) {
        // TLE SOLUTION

        // int i = 0;
        // int j = s.length() - 1;
        // while (i < j) {
        //     if (s[i] == s[j]) {
        //         for (int k = i; k <= j; ++k) {
        //             if (s[k] == s[i]) {
        //                 s.erase(s.begin() + i, s.begin() + k);
        //             }
        //         }
        //         for (int b = j; b >= i; --b) {
        //             if (s[b] == s[j]) {
        //                 s.erase(s.begin() + b, s.begin() + j);
        //             }
        //         }
        //         j = s.length() - 1;
        //     }
        // }
        // return s.length();

        int i = 0, j = s.length() - 1;
        while (i < j && s[i] == s[j]) {
            char same = s[i];
            while (i <= j && s[i] == same)
                ++i;
            while (i <= j && s[j] == same)
                --j;
        }
        return j - i + 1;
    }
};