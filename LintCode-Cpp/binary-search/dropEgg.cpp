/* 

254. Drop Eggs
There is a building of n floors. If an egg drops from the k th floor or above, it will break. If it's dropped from any floor below, it will not break.

You're given two eggs, Find k while minimize the number of drops for the worst case. Return the number of drops in the worst case.

Example
Given n = 10, return 4.
Given n = 100, return 14.

Clarification
For n = 10, a naive way to find k is drop egg from 1st floor, 2nd floor ... kth floor. But in this worst case (k = 10), you have to drop 10 times.

Notice that you have two eggs, so you can drop at 4th, 7th & 9th floor, in the worst case (for example, k = 9) you have to drop 4 times.
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        int x = 0;
        long sum = 0;
        while(sum < n)
        {
            x++;
            sum +=x;
        }
        return x;
    }
    
    // brutal force: O(k)
    // example: n = 1 -> 0
    // n = 2 -> 1
    // n = 3 -> 2 
    // n = 4 -> 2
    // n = 5 -> 3  (2, 3, 4)
    // n = 6 -> 3
    // n = 7 -> 3
    // n = 8 -> 4
    // n = 9 -> 4
    // n = 10 -> 
    // drop at n/2?
    // binary search at 1st egg then linear on 2nd egg will not work.
    // worst case will still be O(n)
    
    // use the approach of x + (x - 1) + (x - 2) + .. + 1 >= n 
    // x is the min number of drop
    // suppose there is min number of drop as x
    // we want to drop at a certain floor so that the min is still the min even if 1st egg breaks
    // if breaks, we have to drop 2nd linearly -> 1 + ?-1 = x -> ? = x -> we'll drop at x
    // if not break, consider it as subproblem with floor starting from x to n
    // since we use one time drop, the min is x-1, repeat the above logic, 
    // we then drop at x + (x - 1) so that even if it breaks, we drop linearly
    // from x + 1 to x + (x - 1) - 1 (x-2 times), we'll find the floor
};