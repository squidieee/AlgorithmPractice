/* 
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (n==0)
            return;
      
        int i1(0), i2(0);
        // solution 1: brutal force O(N2)
        while(i2 < n)
        {
            if(i1 < m+i2)
            {
                if (nums1[i1] >=nums2[i2])
                {
                    // insert nums2[i2]
                    for(int i = m+i2; i > i1; i--)
                    {
                        nums1[i] = nums1[i-1];
                    }
                    nums1[i1] = nums2[i2];
                    i2++;
                }
                i1++;                
            }
            else
            {
                nums1[i1] =  nums2[i2];
                i1++;
                i2++;
            }

        }
        //solution 2: sort from the end: O(N)
        /*
        int i1 = m -1;
        int i2 = n -1;
        int i = m+n-1;
        while (i2 >= 0)
        {
            if (i1 >= 0)
            {
                if (nums1[i1] > nums2[i2])
                {
                    nums1[i] = nums1[i1];
                    i1--;
                }
                else
                {
                    nums1[i] = nums2[i2];
                    i2--;
                }                
            }else
            {
                nums1[i] = nums2[i2];
                i2--;
            }
            i--;
        }
        */
    }
};