class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> asteroidStack;

        for(int i = 0; i < asteroids.size(); i++) {
            if(asteroids[i] > 0) {
                asteroidStack.push_back(asteroids[i]);
            } else {
                while(!asteroidStack.empty() && asteroidStack.back() > 0 && asteroidStack.back() < abs(asteroids[i])) {
                    asteroidStack.pop_back();
                }
                if(!asteroidStack.empty() && asteroidStack.back() == abs(asteroids[i])) {
                    asteroidStack.pop_back();
                } else if(asteroidStack.empty() || asteroidStack.back() < 0) {
                    asteroidStack.push_back(asteroids[i]);
                }
            }
        }

        return vector<int>(asteroidStack.begin(), asteroidStack.end());
    }
};