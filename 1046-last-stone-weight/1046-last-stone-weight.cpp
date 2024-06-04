class Solution {
public:
    int lastStoneWeight(vector<int>& stones) 
    {
        if(stones.size() == 2)
            return abs(stones[0] - stones[1]);
        
        if(stones.size() == 1)
            return stones[0];

        priority_queue<int> pq;

        for(const auto& num: stones)
        {
            pq.push(num);
        }

        while (pq.size() > 1)
        {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
        
            if( abs(num1 - num2) != 0)
            {
                pq.push( abs(num1 - num2) );
            }
        }

        cout << (pq.empty());
        if (pq.empty())
            return 0;

        return pq.top();
    }
};