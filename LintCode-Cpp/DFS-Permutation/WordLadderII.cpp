/*
121. Word Ladder II
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
Example
Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]
Notice
All words have the same length.
All words contain only lowercase alphabetic characters.
*/


class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: a list of lists of string
     */
    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict) {
        dict.insert(start);
        dict.insert(end);
        
        unordered_map<string, int> distances;
        unordered_map<string, vector<string>> graph;
        bfs(end, dict, distances, graph);
        
        vector<string> subset;
        vector<vector<string>> results;
        dfs(start, end, subset, results, distances, graph);
        
        return results;
    }
    
    // take a char from start, change it from 'a' to 'z'
    // see if it is in dict
    // if in dict, call dfs with this word as start
    // if not, call dfs with next char from start
    // Problem 1: hit -> hot -> dot -> hot -> ... endless
    // Sol: Avoid repeatness using a visited array
    // Problem 2: How to make sure it is shortest? We have to go through all paths
    // Sol: Use another memo array to record distance to end by using a bfs from end first
    // this also solves the problem of visited array
    // to further avoid computation, record the map of bfs: record nodes connected to a node
    
    void bfs(string& end, unordered_set<string>& dict, unordered_map<string, int>& distances, unordered_map<string, vector<string>>& graph)
    {
        distances.insert({end, 0});
        
        for(auto it = dict.begin(); it != dict.end(); it++)
        {
            graph.insert({*it, vector<string>()});
        }
        
        queue<string> que;
        que.push(end);
        
        int level(0);
        
        while(!que.empty())
        {
            int len = que.size();
            level++;
            
            for (int k = 0; k < len; k++) // for one level
            {
                string s = que.front();
                que.pop();
                
                // create child from this level
                for(int idx = 0; idx < s.size(); idx++)  //for each char
                {
                    for (int i = 0; i < 26; i++) // variation of this char from 'a' to 'z'
                    {
                        char c = 'a' + i;
                        if (c == s[idx])
                            continue;
                        
                        string temp = s;
                        temp[idx] = c;
                        if (dict.find(temp)!=dict.end())
                        {
                            graph.at(s).push_back(temp);
                            
                            if (distances.find(temp)!=distances.end()) // shortest distance to target
                                continue;
                            cout << temp<< " "<< level << endl;    
                            que.push(temp);
                            distances.insert({temp, level});
                        }
                            
                    }                
                }                
            }
                
        } // while loop
    }
    
    // 
    void dfs(string& start, string& end, vector<string>& subset, vector<vector<string>>& results, unordered_map<string, int>& distances, unordered_map<string, vector<string>>& graph)
    {
        subset.push_back(start);
        if (start == end)
        {
            results.push_back(subset);
        }
        else
        {
            for(string& s: graph.at(start))
            {
                if (distances[s] < distances[start])
                {
                    dfs(s, end, subset, results, distances, graph);
                }
                    
            }
        }
        subset.pop_back();
    }
    
};