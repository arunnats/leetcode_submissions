class Solution {
public:
    int passThePillow(int n, int time) {
        int passes = time / (n-1);
        int dir = passes%2;
        int extraTime = time % (n - 1);

        int ans;

        if(dir){
            ans = n - extraTime;
        }
        else{
            ans = 1 + extraTime;
        }
        return ans;
    }
};