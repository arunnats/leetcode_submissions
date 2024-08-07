class Solution {
public:
    int minOperations(vector<string>& logs){
        int count = 0;

        for(const auto& log: logs){
            if(log == "../")
            {
                if(count > 0)
                    count--;
            }else if (log == "./"){
                continue;
            }else{
                count++;
            }
        }

        return count;    
    }
};