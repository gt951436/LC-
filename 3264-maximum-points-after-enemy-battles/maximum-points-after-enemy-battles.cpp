class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        int n = enemyEnergies.size();
        long long gtpt = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if (currentEnergy < enemyEnergies[0]) {
            return 0;
        }
        int s = 0, e = n - 1;
        while (s <= e) {
            if (enemyEnergies[s] > currentEnergy) {
                if (gtpt == 0) {
                    return 0;
                }
                while (currentEnergy < enemyEnergies[s]) {
                    currentEnergy += enemyEnergies[e];
                    e--;
                }
            } else if (enemyEnergies[s] <= currentEnergy) {
                int timesDefeated = currentEnergy / enemyEnergies[s];
                currentEnergy %= enemyEnergies[s];
                gtpt += timesDefeated;
            }
        }
        return gtpt;
          
    }
};