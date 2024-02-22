class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
           vector<int> p(n+1, 0);
        for(int i=0; i<trust.size(); i++){
            p[trust[i][1]]++;
            p[trust[i][0]]--; 
        }
        int label = -1, cnt = 0;
        for(int i=1; i<=n; i++){
            if(label == -1 && p[i] == n-1){
                label = i;
                cnt++;
                if(cnt > 1) return -1;
            } 
        }
        return label;
    }
};