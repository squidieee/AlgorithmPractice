/* 
895. Friend Request
Given an array Ages of length n, where the first i elements represent the age of the individual i. Find total number of friend requests sent by this n person. There are some requirements:

if Age(B) <= (1/2)Age(A) + 7, A will not send a request to B.
if Age(B) > Age(A), A will not send a request to B.
if Age(B) < 100 and Age(A) > 100, A will not send a request to B.
If it does not satisfy 1,2,3, then A will send a request to B
Example
Given Ages = [10,39,50], return 1.

Explanation:
Only people of age 50 will send friend requests to people of age 39.
Given Ages = [101,79,102], return 1.

Explanation:
Only people of age 102 will send friend requests to people of age 101.
Notice
Ages.length <= 1000。
Everyone's age is greater than 0, less than 150
*/

class Solution {
public:
    /**
     * @param ages: The ages
     * @return: The answer
     */
    int friendRequest(vector<int> &ages) {
        if (ages.size() <= 1) return 0;
        std::sort(ages.begin(), ages.end());
        int cnt(0);
        for(int i = ages.size() - 1; i >= 0; i--)
        {
            // age at 14: will not add any people
            // requirement conflicts with each other
            if(ages[i] <= 14 ){
                continue;
            }
            
            // left half
            int lowerBound = ages[i]/2 + 7;
            if(ages[i] > 100)
                lowerBound = max(lowerBound, 99); 

            int idx = binarySearch1(ages, 0, i - 1, lowerBound);
            if (idx != -1)
                cnt += i - idx;
            
            // right half
            idx = binarySearch2(ages, i + 1, ages.size() - 1, ages[i]);
            if (idx != -1)
                cnt += idx - i;
        }
        
        return cnt;
    }
    
    // find the last one which is equal to target
    int binarySearch2(vector<int>& ages, int start, int end, int target)
    {
        if (start > end) return -1;
        
        int left(start), right(end);
        while(left + 1 < right)
        {
            int mid = left + (right - left)/2;
            if (target >= ages[mid])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        // return the index of last repeated one
        if (ages[right] == target) return right;
        if (ages[left] == target) return left;
        
        return -1;
    }
    
    // find the first one which > target
    int binarySearch1(vector<int>& ages, int start, int end, int target)
    {
        if (start > end) return -1;
        int left(start), right(end);
        while(left + 1 < right)
        {
            int mid = left + (right - left)/2;
            if (target >= ages[mid])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        
        // return index that is the first > target
        if (ages[left] > target) return left;
        if (ages[right] > target) return right;
        return -1;
    }
};

// sort it first O(nlogn)
// from end to start, check if one will send to another
// O(n - 1 + n - 2 + ... + 1) = O(n^2) not good
// there is a lower bound of sending
// after sorting, binary search to locate the lower bound O(logn)
// O(nlogn)