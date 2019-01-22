/* 
148. Sort Colors
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Example
Given [1, 0, 1, 2], sort it in-place to [0, 1, 1, 2].

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

Notice
You are not suppose to use the library's sort function for this problem.
You should do it in-place (sort numbers in the original array).
*/

class Solution {
public:
    /**
     * @param nums: A list of integer which is 0, 1 or 2 
     * @return: nothing
     */
    void sortColors(vector<int> &nums) {
        if (nums.empty()) return;
        int left(0), index(0), right(nums.size() - 1);
        
        while(index <= right) 
        {
            if (nums[index] == 0)
            {
                std::swap(nums[left], nums[index]);
                if (index == left)
                    index++;
                left++;
            }
            else if(nums[index] == 2)
            {
                std::swap(nums[right], nums[index]);
                right--;
            }
            else
            {
                index++;
            }
            
        }
    }
};


// ver 1: count 0, 1, 2 and construct a new array
// Time O(n) Space O(k)
// but it takes two-pass and extra space

// ver 2: two pointers
// init with all 1
// start for 0, end for 2
// all the rest for 1
// it takes one pass, but still extra space O(n)

// ver 3: still two pointers
// left -> look for all non-0s
// right -> look for all 0s
// swap them
// this requires one pass
// 2nd pass: 
// start with the last 0
// partition 1 and 2
// constant space, but two pass

// ver 4: three pointers
// left, right, index
// use left to record the last 0 (will be left - 1)
// use right to record the first 2 (right + 1)
// use index to iterate throught the index:
// if 0, swap with left, left ++
// if 2, swap with right, right --
// if 1, do nothing
// one pass, constant space
// note that only swap with left or right needs another check
// add if (left == index) index++; to avoid inf-loop