class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, unordered_set<int>> trustMp;
        for(auto tPair : trust){
            int person = tPair[0], trustedPerson = tPair[1];
         
            trustMp[person].insert(trustedPerson);
        }
        int leftPer = 1, rightPer = n;
        while(leftPer < rightPer){
            if(trustMp[leftPer].count(rightPer) != 0){
                leftPer++;
            }else rightPer--;
        }
       
        int cand = leftPer, candTrustNumber = 0;
        for(auto & tPair : trust){
            if(tPair[0] == cand){
                candTrustNumber--;
            }else if(tPair[1] == cand){
                candTrustNumber++;
            }
        }
        return (candTrustNumber == n-1) ? cand : -1;
    }
};