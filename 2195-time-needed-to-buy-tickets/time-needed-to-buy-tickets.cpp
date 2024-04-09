class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time=0;
        for(int i=0;i<tickets.size();++i){
            if(i<=k){
                if(tickets[i]<=tickets[k])
                time+=tickets[i];
                else
                time+=tickets[k];
            }
            else{
                if(tickets[i]<tickets[k])
                time+=tickets[i];
                else
                time+=(tickets[k]-1);
            }
        }
        return time;
    }
};