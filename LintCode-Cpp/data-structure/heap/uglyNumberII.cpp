/* 
4. Ugly Number II
Ugly number is a number that only have factors 2, 3 and 5.

Design an algorithm to find the nth ugly number. The first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12...

Example
If n=9, return 10.

Challenge
O(n log n) or O(n) time.

Notice
Note that 1 is typically treated as an ugly number.
*/

class Solution {
public:
    /**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
    int nthUglyNumber(int n) {
        
        std::priority_queue<long, vector<long>, std::greater<long>> min_heap;
        unordered_set<long> set;
        
        int ugly[3] = {2,3,5};
        
        min_heap.push(1);
        for(int i = 1; i < n; i++)
        {
            long num = min_heap.top();
            min_heap.pop();
            for(int k = 0; k < 3; k++)
            {
                long nextNum = ugly[k] * num;
                if (set.find(nextNum)==set.end())
                {
                    min_heap.push(nextNum);
                    set.insert(nextNum);
                }                
            }
        }
        
        return (int) min_heap.top();
    }
};    
    // 1 -> 2, 3, 5
    // 2 -> 4, (6), 10
    // 3 -> (6), 9, 15
    // 1. need a data structure to record what has been found: map or set
    // 2. need a mechanism to "sort" them, so that we know the order
    //    we update a min value after adding new vals, remove this min value, 
    //    keep track of its order of removing
    //    so that when we remove the nth min, this will be the required result.

    // Why we record a min?
    // - If we do brutal force by inserting new val into a sorted array,
    //   there is a lowerbound of the index of insertion, so that from this val,
    //   there is no point of keeping vals below the lowerbound
    //   at least, we won't insert before the min, since it is min.
    
    // Problem: how to make sure the min val is the true min val
    //          so it will not be updated later?
    // Answer: because all expaned vals are acquired by multiplying x2, x3, and x5
    //         to each val in the current set, so if min < all other val,
    //         then min < all other val x2, x3, x5
    
    