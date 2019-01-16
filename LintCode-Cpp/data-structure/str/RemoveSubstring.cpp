/* 
624. Remove Substrings
Given a string s and a set of n substrings. You are supposed to remove every instance of those n substrings from s so that s is of the minimum length and output this minimum length.

Example
Given s = ccdaabcdbb, substrs = ["ab", "cd"]
Return 2

Explanation:
ccdaabcdbb -> ccdacdbb -> cabb -> cb (length = 2)
*/

class Solution {
public:
    /*
     * @param s: a string
     * @param dict: a set of n substrings
     * @return: the minimum length
     */
    int minLength(string &s, unordered_set<string> &dict) {
        if (s.size() == 0) return 0;
        return bfs(s, dict);
    }
    
    int bfs(string &s, unordered_set<string> &dict){
        queue<string> que;
        que.push(s);
        
        unordered_set<string> memo;
        memo.insert(s);
        
        int minLength = s.size();
        
        while(!que.empty())
        {
            string str = que.front();
            que.pop();
            for(auto it = dict.begin(); it != dict.end(); it++)
            {
                string substr = *it;
                //vector<int> found = findSubStr(str, substr);
                int found = str.find(substr);
                while(found!=-1)
                {
                    // compute new str
                    string childStr;
                    if (found == 0)
                        childStr = str.substr(substr.length(), str.length() - substr.length());
                    else
                        childStr = str.substr(0, found) + str.substr(found+substr.length(), str.length()-found-substr.length());
                    // it is not computed before
                    if (memo.find(childStr) == memo.end())
                    {
                        memo.insert(childStr);
                        que.push(childStr);
                        if (childStr.size() < minLength)  minLength = childStr.size();
                    }
                    found = str.find(substr, found + 1);
                }

                
                // for each found position
                /*
                for(int i = 0; i < found.size(); i++)
                {
                    // compute new str
                    string childStr;
                    if (found[i] == 0)
                        childStr = str.substr(substr.length(), str.length() - substr.length());
                    else
                        childStr = str.substr(0, found[i]) + str.substr(found[i]+substr.length(), str.length()-found[i]-substr.length());
                    // it is not computed before
                    if (memo.find(childStr) == memo.end())
                    {
                        memo.insert(childStr);
                        que.push(childStr);
                        if (childStr.size() < minLength)  minLength = childStr.size();
                    }                    
                }
                */
            }
        }
        return minLength;
    }
    
    // it is a problem asking to traverse to the end of the tree and find the node with minLength
    // the sequence of removing words matter, it will influence the leaf's final length
    // so we need to traverse the whole tree and find the node with min length
    // Note that writing a naive string search algorithm is not effecicent since it takes O(m*n)
    // m is str size and n is substr size
    // so either use the find function provided by standard library or write KMP string search on my own
    
    vector<int> findSubStr(string& str, string& subStr) // naive implemtation
    {
        vector<int> pos;
        
        if (str.size() == 0 || str.size() < subStr.size())
            return pos;
            
        if (str.size() == subStr.size() && str == subStr) 
        {
            pos.push_back(0);
        }
        
        for(int i = 0; i <= str.size() - subStr.size(); i++)
        {
            if( str.substr(i, subStr.size()) == subStr)
                pos.push_back(i);
        }
        
        return pos;
    }
};