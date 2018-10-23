/*
605. Sequence Reconstruction
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 10^4. Reconstruction means building a shortest common supersequence of the sequences in seqs (i.e., a shortest sequence so that all sequences in seqs are subsequences of it). Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Example
Given org = [1,2,3], seqs = [[1,2],[1,3]]
Return false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Given org = [1,2,3], seqs = [[1,2]]
Return false
Explanation:
The reconstructed sequence can only be [1,2].

Given org = [1,2,3], seqs = [[1,2],[1,3],[2,3]]
Return true
Explanation:
The sequences [1,2], [1,3], and [2,3] can uniquely reconstruct the original sequence [1,2,3].

Given org = [4,1,5,2,6,3], seqs = [[5,2,6,3],[4,1,5,2]]
Return true
 */


 class Solution {
public:
    /**
     * @param org: a permutation of the integers from 1 to n
     * @param seqs: a list of sequences
     * @return: true if it can be reconstructed only one or false
     */
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs) {
        
        if (org.empty() && seqs.empty()) return true;
        if (org.empty()) return false;
        if (seqs.empty()) return false;
        
        // compute in degrees and record point-To nodes
        vector<int> indegrees(org.size());
        vector<vector<int>> pointTo(org.size());
        
        bool emptySeq(true);
        for(auto s: seqs)
        {
            if (!s.empty())
            {
                for(int i = 1;i < s.size();i++)
                {
                    if (s[i] <= 0 || s[i] > org.size()) // be careful of invalid input from seqs
                        return false;
                    indegrees[s[i] - 1]++;
                    if (s[i-1] <= 0 || s[i-1] > org.size())
                        return false;
                    pointTo[s[i-1] - 1].push_back(s[i] - 1);
                }  
                emptySeq = false;
            }
        }
        if (emptySeq) return false;
        
        // bfs
        queue<int> que;
        
        for(int i = 0;i < indegrees.size();i++)
        {
            if(indegrees[i] == 0) que.push(i);
        }
        
        int visited(0);
        
        while(!que.empty())
        {
            if (que.size() > 1)  return false;
            
            int node = que.front();
            que.pop();
            
            if (org[visited] != node + 1) return false;
            
            visited++;
            
            for(int i = 0; i < pointTo[node].size(); i++)
            {
                indegrees[pointTo[node][i]]--;
                
                if ( indegrees[pointTo[node][i]] == 0)
                {
                    que.push(pointTo[node][i]);
                }

            }
        }
        
        if (visited != org.size()) return false;
        
        return true;
    }
    
};