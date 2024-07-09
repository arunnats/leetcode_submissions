class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) 
    {
        double time = customers[0][0];
        double finTime = time + customers[0][1];
         cout<< "finTime" ;
            cout<< finTime ;
            cout<< "\n"; 
        double waitTime = finTime - time;
        double n = customers.size();

        for(int i = 1; i < n; i++)
        {
            time = customers[i][0];
            finTime = max(finTime + customers[i][1], time + customers[i][1]);
            waitTime += finTime - time;
            cout<< "finTime" ;
            cout<< finTime ;
            cout<< "\n"; 
        }

        return waitTime / n;
    }
};