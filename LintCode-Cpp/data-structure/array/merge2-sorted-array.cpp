/* 
6. Merge Two Sorted Arrays
Merge two given sorted integer array A and B into a new sorted integer array.

Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge
How can you optimize your algorithm if one array is very large and the other is very small?
*/

class Solution {
public:
    /**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        //return mergehelper1(A,B);
        if (A.size() > B.size())
            return mergehelper2(A, B);
        else
            return mergehelper2(B, A);
    }
    
    // Time O(m + n)
    // Space O(min(m + n))
    vector<int> mergehelper2(vector<int> &L, vector<int>& S)
    {
        if (L.empty()) return S;
        if (S.empty()) return L;
        
        int m = L.size();
        int n = S.size();
        L.resize(m + n);
        
        int iL(m-1), iS(n-1), iM(L.size()-1); 
        
        while(iM >= 0)
        {
            if (iL < 0)
            {
                L[iM--] = S[iS--];
                continue;
            }
            
            if(iS < 0)
            {
                break;
            }
            
            if(L[iL] > S[iS])
            {
                L[iM] = L[iL--];
            }
            else
            {
                L[iM] = S[iS--];
            }
            
            iM--;
        }
        
        return L;
    }
    
    // Time O(m + n)
    // Space O(m + n)
    vector<int> mergehelper1(vector<int> &A, vector<int> &B)
    {
        if (A.empty()) return B;
        if (B.empty()) return A;
        
        vector<int> C;
        int len = A.size() + B.size();
        int ia(0), ib(0);

        while(C.size() < len)
        {
           if(ia > A.size() - 1)
           {
               C.push_back(B[ib]);
               ib++;
               continue;
           }
           
           if(ib > B.size() - 1)
           {
               C.push_back(A[ia]);
               ia++;
               continue;
           }
           
           if (A[ia] > B[ib])
           {
               C.push_back(B[ib]);
               ib++;
           }
           else
           {
               C.push_back(A[ia]);
               ia++;
           }
        }
        
        return C;
    }
};