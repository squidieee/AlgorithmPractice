/* 
1387. Binary Trees With Factors

Given an array of unique integers, each integer is strictly greater than 1.

We make a binary tree using these integers and each number may be used for any number of times.

Each non-leaf node's value should be equal to the product of the values of it's children.

How many binary trees can we make? Return the answer.

Example
Example 1:

Input: A = [2, 4]
Output: 3
Explanation: We can make these trees: [2], [4], [4, 2, 2]
Example 2:

Input: A = [2, 4, 5, 10]
Output: 7
Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
Notice
1 <= A.length <= 1000.
2 <= A[i] <= 10 ^ 9.
*/

class Solution {
public:
    /**
     * @param A: 
     * @return: nothing
     */
    int numFactoredBinaryTrees(vector<int> &A) {
        // sort 
        sort(A.begin(), A.end());
        
        // compute factors
        unordered_map<int, int> map;
        vector<vector<pair<int,int>>> factors(A.size()); 
        for(int i = 0; i < A.size(); i++)
        {
            map.insert({A[i], i});
            factors[i].push_back(std::make_pair(1, A[i]));
            
            int UB = std::sqrt(A[i]);
            for (int j = 0; A[j] <= UB; j++)
            {
                if (A[i] % A[j] != 0) continue;
                
                int f2 = A[i] / A[j];
                if( map.find(f2) != map.end() )
                {
                    factors[i].push_back(std::make_pair(A[j], f2));
                }
            }
        }
        
        // compute number of trees
        vector<int> result(A.size(), 1);
        int grandSum = 0;
        for(int i = 0; i < factors.size(); i++)
        {
            if (factors[i].size() == 1)
            {
                grandSum++;
                continue;
            }
            
            for (int j = 1; j < factors[i].size(); j++)
            {
                int combined = result[map[factors[i][j].first]] * result[map[factors[i][j].second]];
                if ( factors[i][j].first != factors[i][j].second) combined *= 2;
                
                result[i] += combined;
            }
            
            grandSum += result[i];
        }
        return grandSum;
    }
};

// dp
// record the number of trees for each factor
// the final result is the sum of results of all numbers

// sort the vector first

// pre-compute the factor for each number
// store in a vector

// for each number, for each factor pairs [num1, num2],
// if size > 1, result = f[num1] * f[num2], if num1 != num2, result *= 2
// the sum of all pairs is the result for this number

// Time O(nlogn) + O(n^3/2) + O(numOfFactors)
// Space O(n) + O(numOfFactors)