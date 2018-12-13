/* 
654. Sparse Matrix Multiplication
Given two Sparse Matrix A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example
A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/

class Solution {
public:
    /**
     * @param A: a sparse matrix
     * @param B: a sparse matrix
     * @return: the result of A * B
     */
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        vector<vector<int>> results;
        if (A.empty() || B.empty()) return results;
        
        results.resize(A.size(), vector<int>(B[0].size()));
        // store all non-zero vals of B in a vector of hashmap: columnwise
        vector<unordered_map<int, int>> vB(B.size());
        for(int j = 0; j < B[0].size(); j++)
        {
            for(int i = 0; i < B.size(); i++)
            {
                if (B[i][j]!=0)
                    vB[j].insert({i, B[i][j]});
            }
        }
        
        // multiply non-zero vals
        for(int i = 0; i < A.size(); i++)
        {
            for(int j = 0; j < A[0].size(); j++)
            {
                if (A[i][j]!=0)
                {
                    for(int k = 0; k < vB.size(); k++)
                    {
                        if(vB[k].find(j)!=vB[k].end())
                        {
                            results[i][k] += A[i][j] * vB[k].at(j);
                        }
                    }
                }
            }
        }
        
        return results;
    }
    
    // brutal force: 
    // nxn * nxn Time O(n^3)
    // hashmap: 
    // store non-zero vals in map as val and index as key
    // do it columnwise for B
    // Time O(n^2) to store in a vector of hash map Space O(n^2)
    // for each row of A, find non-zero element, loop through vector of hash map
    // to find if there is same index as key Time O(n^2 * k)
};