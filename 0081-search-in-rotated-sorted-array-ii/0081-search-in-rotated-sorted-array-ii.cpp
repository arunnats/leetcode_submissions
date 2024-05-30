const int ZERO = [](){
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
return 0;
}();
class Solution {
public:
    int search(vector<int>& arr, int target) 
    {
        int l = 0;
        int r = arr.size()-1;

        while(l <= r)
        {
            int mid = ( l + r ) / 2;

            if (arr[mid] == target) 
                return true;
            else if (arr[l] < arr[mid]) 
            {
                if (arr[l] <= target && target <= arr[mid]) 
                {
                    r = mid - 1;
                }
                else 
                {
                    l = mid + 1;
                }
            }
            else if (arr[r] > arr[mid]) 
            {
                if (arr[mid] <= target && target <= arr[r]) 
                {
                    l = mid + 1;
                }
                else 
                {
                    r = mid - 1;
                }
            }
            else 
            {
                if (arr[l] == arr[mid]) 
                {
                    l++;
                }
                if (arr[r] == arr[mid]) 
                {
                    r--;
                }
            }
        }

        return false;
    }
};
