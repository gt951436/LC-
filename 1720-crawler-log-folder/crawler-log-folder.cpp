class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folderCnt = 0;
        for (int i = 0; i < logs.size(); ++i) {
            if (logs[i] == "../") {
                if (folderCnt > 0) {
                    --folderCnt;
                }
            } else if (logs[i] != "./")
                ++folderCnt;
        }
        return folderCnt;
    }
};