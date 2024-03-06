class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int n = asteroids.size();
        int i = 0;
        while (i < n) {
            int temp = asteroids[i];
            if (res.size() == 0) {
                res.push_back(temp);
                ++i;
                continue;
            }
            int last = res.back();
            if ((temp > 0 && last > 0) || (temp < 0 && last < 0)) {
                res.push_back(temp);
                ++i;
            }
            else{
                if(temp<0){
                    if(abs(temp)==last){
                        res.pop_back();
                        ++i;
                    }
                    else if(abs(temp)>last){
                        res.pop_back();
                    }
                    else{
                        ++i;
                    }
                }
                else{
                    res.push_back(temp);
                    ++i;
                }
            }
        }
        return res;
    }
};