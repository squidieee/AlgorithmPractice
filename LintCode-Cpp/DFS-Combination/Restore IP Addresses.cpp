/* 
426. Restore IP Addresses

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

(Your task is to add three dots to this string to make it a valid IP address. Return all possible IP address.)

Example
Example 1:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
Explanation: ["255.255.111.35", "255.255.11.135"] will be accepted as well.
Example 2:

Input: "1116512311"
Output: ["11.165.123.11","111.65.123.11"]
Notice
You can return all valid IP address in any order.
*/

class Solution {
public:
    /**
     * @param s: the IP string
     * @return: All possible valid IP addresses
     */
    vector<string> restoreIpAddresses(string &s) {
        vector<int> subset;
        vector<string> result;
        dfs(s, 0, subset, result);
        return result;
    }
    
    void dfs(string &s, int start, vector<int>& subset, vector<string>& result)
    {
        if (subset.size() == 4) 
        {
            if (start != s.size()) return;
            
            string str;
            for(auto& num: subset)
            {
                str += to_string(num);
                str +=".";
            }
            str.resize(str.size() - 1);
            result.push_back(str);
            return;
        }
        
        int cnt = 4 - subset.size();
        if (s.size() - start < cnt) return;
        if (s.size() - start > cnt * 3) return;
        
        for(int len = 1; len <= 3; len++)
        {
            if (start + len - 1 > s.size() - 1)  return;
            if (len != 1 && s[start] == '0') return;
            
            int num = stoi(s.substr(start, len));
            if (num > 255) return;
            
            subset.push_back(num);
            dfs(s, start + len, subset, result );
            subset.pop_back();
        }
    }
};

// the len should be between 4 and 12
// each number has the len between 1 and 3
// for each number, we get an alternative answer by iter from 1 to 3
// next recur in invalid when the rest of len < cnt or rest of len > cnt*3
// valid ip address: 0~255
// for 2 or 3 digit number, can not start with 0