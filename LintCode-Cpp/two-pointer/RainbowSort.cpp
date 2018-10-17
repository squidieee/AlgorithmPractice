/* 
143. Sort Colors II
Given an array of n objects with k different colors (numbered from 1 to k), sort them so that objects of the same color are adjacent, with the colors in the order 1, 2, ... k.

Example
Given colors=[3, 2, 2, 1, 4], k=4, your code should sort colors in-place to [1, 2, 2, 3, 4].

Challenge
A rather straight forward solution is a two-pass algorithm using counting sort. That will cost O(k) extra memory. Can you do it without using extra memory?

Notice
You are not suppose to use the library's sort function for this problem.

k <= n
*/

class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // rainbow sort: nlogk
        if (colors.empty() || k <=1) return;
        sortColor(colors, 0, colors.size()-1, 1, k);
        
        
    }
    
    void sortColor(vector<int> &colors, int start,int end,int startk, int endk)
    {
        if (startk == endk || start == end)
            return;
            
        int midk = startk + (endk - startk) / 2;
        
        int left(start), right(end);
        while(left <= right)
        {
            while(left <=right && colors[left] <= midk) // garrantee things <= mid will be on the left
            {
                left++;
            }
            while(left<=right && colors[right] > midk)
            {
                right--;
            }
            
            if (left <=right)
            {
                swap(colors[left], colors[right]);
                left++;
                right--;
            }
        }
        
        sortColor(colors, start, left-1, startk, midk);
        sortColor(colors, left, end, midk + 1, endk);
    }
};