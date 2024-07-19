class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> rowMin, colMax;
        for (int i = 0; i < matrix.size(); ++i) {
            rowMin.push_back(*min_element(matrix[i].begin(), matrix[i].end()));
        }
        for (int i = 0; i < matrix[0].size(); i++) {

            int cMax = INT_MIN;
            for (int j = 0; j < matrix.size(); j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            colMax.push_back(cMax);
        }
        vector<int> ans;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};