class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int Drunk = 0;
        while (numBottles >= numExchange) {
            Drunk += numExchange;
            numBottles-=numExchange;
            numBottles+=1;
        }
        return numBottles+Drunk;
    }
};