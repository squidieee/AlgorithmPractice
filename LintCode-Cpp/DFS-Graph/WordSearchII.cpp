/*
132. Word Search II
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. One character only be used once in one word. No same word in dictionary

Example
Given matrix:

doaf
agai
dcan
and dictionary:

{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}


dog:
doaf
agai
dcan
dad:

doaf
agai
dcan
can:

doaf
agai
dcan
again:

doaf
agai
dcan
Challenge
Using trie to implement your algorithm.
*/
class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    vector<string> wordSearchII(vector<vector<char>> &board, vector<string> &words) {
        vector<string> result;
        if (board.empty() || words.empty()) return result;
        
        unordered_set<string> prefix;
        unordered_map<string, bool> wordMap;
        
        vector<pair<int,int>> starts;
        // store all prefix and words in an unordered_set
        for(string& s: words)
        {
            // find whether matrix has the first char of word
            // store it in a vector if not exist in prefix set
            if (prefix.find(s.substr(0,1)) == prefix.end())
            {
                for (int i = 0; i < board.size(); i++)
                {
                    for(int j = 0; j < board[0].size(); j++)
                    {
                        if (board[i][j] == s[0])
                        {
                            starts.push_back(std::make_pair(i,j));
                        }
                            
                    }
                }
            }
            
            if (wordMap.find(s)==wordMap.end())
            {
                wordMap.insert({s, false});
            }
            
            for(int len = 1; len < s.size(); len++)
            {
                string subS = s.substr(0, len);
                if (prefix.find(subS)==prefix.end())
                {
                    prefix.insert(subS);
                }
            }
            
        }
        

        string subset;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));        

        for(int i = 0; i < starts.size(); i++)
        {
            subset.push_back(board[starts[i].first][starts[i].second]);
            visited[starts[i].first][starts[i].second] = true;

            dfs(board, starts[i].first, starts[i].second, prefix, wordMap, visited, subset, result);
            
            subset.pop_back();
            visited[starts[i].first][starts[i].second] = false;
        }
    
    
        return result;
        
        
    }
    // in main:
    // store all prefix and words in an unordered_set
    // find whether matrix has the first char of word, store it in a vector if/not exist in prefix set
    // do dfs for each of vector
    
    // in recursive function:
    // go four directions
    // if nextChar is valid
    // add it into a substr
    // if new substr (current + nextChar) exist in word map, set map to true
    // if new substr (current + nextChar) exist in prefix, recursively call with new substr
    // back trace to withdraw it from substr
    // Problem: go back to previous location
    // Sol: use a visited matrix
    void dfs( vector<vector<char>>& board, int x, int y, unordered_set<string>& prefix, unordered_map<string, bool>& word, vector<vector<bool>>& visited, string& subset, vector<string>& result)
    {
        if (word.find(subset)!=word.end() && !word.at(subset))
        {
            result.push_back(subset);
            word.at(subset) = true;
        }
            
        
        for(int i = 0; i < 4; i++)
        {
            int nextX = x + _dirX[i];
            int nextY = y + _dirY[i];
            
            if (!isValid(nextX, nextY, board))
                continue;
            
            if (visited[nextX][nextY])
                continue;
            
            subset.push_back(board[nextX][nextY]);
            visited[nextX][nextY] = true;
            
            if (word.find(subset) != word.end() && !word.at(subset))
            {
                result.push_back(subset);
                word.at(subset) = true;
            }
            
            if(prefix.find(subset)!=prefix.end())
                dfs(board, nextX, nextY, prefix, word, visited, subset, result);
            
            subset.pop_back();
            visited[nextX][nextY] = false;
        }
    }
    
    bool isValid(int x, int y, vector<vector<char>>& board)
    {
        if (x >=0 && x < board.size() && y >=0 && y < board[0].size())
            return true;
            
        return false;
    }
    
private:
    int _dirX[4] = {-1, 0, 1, 0};
    int _dirY[4] = {0, 1, 0, -1};

};