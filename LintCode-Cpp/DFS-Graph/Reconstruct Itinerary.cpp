/*
1288. Reconstruct Itinerary

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Example
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"].
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order
Notice
1.If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
2.All airports are represented by three capital letters (IATA code).
3.You may assume all tickets form at least one valid itinerary.
*/

class Solution {
public:


    vector<string> findItinerary(vector<vector<string>> &tickets) {
        // sort tickets
        sort(tickets.begin(), tickets.end(), less_than_key());
        
        // save code in hash map: departure as key and indices as val
        unordered_map<string, vector<int>> map;
        for(int i =0; i < tickets.size(); i++)
        {
            map[tickets[i][0]].push_back(i);
        }
        
        // create visited array
        vector<bool> visited(tickets.size(), false);
        
        // dfs
        vector<string> subset;
        subset.push_back("JFK");
        dfs(tickets, map, visited, subset);
        
        return subset;
    }
    
    // get the dest array from the depart
    // for each dest, if not visited, add it to the subset, mark as visited
    // then go to the dest of dest
    // quit when there is no dest
    // or subset.size() == tickets.size() + 1
    void dfs(vector<vector<string>>& tickets, unordered_map<string, vector<int>>& map, vector<bool>& visited, vector<string>& subset)
    {
        if (subset.size() == tickets.size() + 1) return;
        if (map.find(subset.back()) == map.end()) return;
        
        for(int i = 0; i < map[subset.back()].size(); i++)
        {
            int tIdx = map[subset.back()][i];
            if (visited[tIdx]) continue;
            
            subset.push_back(tickets[tIdx][1]);
            visited[tIdx] = true;
            
            dfs(tickets, map, visited, subset);
            
            if (subset.size() == tickets.size() + 1) return;
            
            visited[tIdx] = false;
            subset.pop_back();
        }
    }
    
    struct less_than_key
    {
        
        inline bool operator() (const vector<string>& t1, const vector<string>& t2)
        {
            return strSmallerThan(t1[1], t2[1]);
        }
        
        bool strSmallerThan(const string& A, const string& B)
        {
            for(int i = 0; i < A.size(); i++)
            {
                if (A[i] == B[i])
                    continue;
                    
                return A[i] < B[i];
            }
            return false;
        }
    };

};


// Sol1: hash map [wrong -- loop exists]
// convert all pairs into hash map with departure as key and dest as val
// find "JFK" and its destination, then find the destination as key etc
// Space O(n) Time O(n)

// Sol2: dfs
// TODO: optimize