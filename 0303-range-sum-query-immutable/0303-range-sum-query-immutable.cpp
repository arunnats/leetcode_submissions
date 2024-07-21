class NumArray {
public:
    vector<int> PreSum;
    NumArray(vector<int>& nums) 
    {
        PreSum.resize(nums.size());
        PreSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            PreSum[i] = PreSum[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) 
    {
        if(left == 0) return PreSum[right];
        else return PreSum[right] - PreSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */