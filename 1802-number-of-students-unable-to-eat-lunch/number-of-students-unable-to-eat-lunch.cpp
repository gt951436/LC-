class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int sq = 0;
        int cir = 0;
        for (auto it : students) { // counting the preferences
            if (it == 1)
                sq++;
            else
                cir++;
        }
        for (auto it : sandwiches) {
            if (it == 0) {
                if (cir > 0)
                    cir--;
                else
                    break;
            }
            if (it == 1) {
                if (sq > 0)
                    sq--;
                else
                    break;
            }
        }
        return sq + cir;
    }
};