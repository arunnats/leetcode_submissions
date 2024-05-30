class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        // int n = nums1.size() + nums2.size();

        // nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        // sort(nums1.begin(),nums1.end());

        // int total = nums1.size();

        // if (total % 2 == 1) {
        //     return static_cast<double>(nums1[total / 2]);
        // } 
        // else 
        // {
        //     int middle1 = nums1[total / 2 - 1];
        //     int middle2 = nums1[total / 2];
        //     return (static_cast<double>(middle1) + static_cast<double>(middle2)) / 2.0;
        // }
        // return 0;

        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0, m1 = 0, m2 = 0;

        for (int count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;

            if (i != n && j != m)
            {
                if (nums1[i] > nums2[j]) 
                {
                    m1 = nums2[j++];
                } 
                else 
                {
                    m1 = nums1[i++];
                }
            }
            else if (i < n) 
            {
                m1 = nums1[i++];
            } 
            else 
            {
                m1 = nums2[j++];
            }
        }

        if ((n + m) % 2 == 1) {
            return static_cast<double>(m1);
        } else {
            double ans = static_cast<double>(m1) + static_cast<double>(m2);
            return ans / 2.0;
        }
        return 0;
    }
};