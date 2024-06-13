class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int gt=0;
        for (int i = 0; i < students.size(); ++i) {
            gt += abs(students[i] - seats[i]);
        }
        return gt;
    }
};