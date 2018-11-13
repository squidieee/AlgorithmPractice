/* 
402. Continuous Subarray Sum
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return the firstone you find)

Example
Give [-3, 1, 3, -3, 4], return [1,4].
*/

class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &A) {
        // [1] -> 1 return [0, 0]
        // [1, -2] -> 1 return [0, 0]
        // [.., -2] -> -2 or prevMax + -2 return [j, j] or [start, j] to find all local max
        // find global among all local max
        vector<int> result;
        if (A.empty()) return result;
        
        int iMax = A[0];
        int istart(0);
        
        int AMax = A[0];
        int start(0), end(0);
        
        for(int i = 1; i < A.size(); i++)
        {
            if (iMax >= 0)
            {
                iMax = A[i] + iMax;
            }
            else
            {
                iMax = A[i];
                istart = i;
            }
            
            if (iMax > AMax)
            {
                AMax = iMax;
                end = i;
                start = istart;
            }
        }
        result.push_back(start);
        result.push_back(end);
       
        return result;
        
    }
};