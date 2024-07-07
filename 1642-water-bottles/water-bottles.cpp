class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int Drunk = 0;
        while (numBottles >= numExchange) {
            int newBottles = numBottles / numExchange;
            Drunk += (numExchange * newBottles);
            numBottles -= (numExchange * newBottles);
            numBottles += newBottles;
        }
        return Drunk + numBottles; // in case numBottles<numExchage
    }
};