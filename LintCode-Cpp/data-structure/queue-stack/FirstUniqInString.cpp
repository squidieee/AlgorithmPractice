/* 
209. First Unique Character in a String
Find the first unique character in a given string. You can assume that there is at least one unique character in the string.

Example
For "abaccdeff", return 'b'.
*/

class Solution {
public:
    /**
     * @param str: str: the given string
     * @return: char: the first unique character in a given string
     */
    char firstUniqChar(string &str) {
        if (str.size() == 1) return str[0];
        //return hashUniqChar(str);
        return linkedListUniqChar(str);
    }
    
    // hash map: Time O(n) two passes; Space O(n)
    char hashUniqChar(string& str)
    {
        unordered_map<char, bool> map;
        for(int i = 0; i < str.size(); i++)
        {
            if (map.find(str[i])==map.end())
            {
                map.insert({str[i], false});
            }
            else
                map.at(str[i]) = true;
        }
        
        for(int i = 0; i < str.size(); i++)
        {
            if( !map.at(str[i]) )
                return str[i];
        }
    }
    
    // linked list version: Time O(n) but single pass; Space O(n*2)
    char linkedListUniqChar(string& str)
    {
        unordered_map<char, shared_ptr<Node>> map;
        
        shared_ptr<Node> dummy(new Node('0'));
        dummy->next = std::make_shared<Node> (str[0]);
        
        shared_ptr<Node> end = dummy->next;
        map.insert({str[0], dummy});
        
        for(int i = 1; i < str.size(); i++)
        {
            if (map.find(str[i]) == map.end())
            {
                map.insert({str[i], end});
                end->next = std::make_shared<Node> (str[i]);
                end = end->next;
            }
            else
            {
                if (map.at(str[i])!=nullptr)
                {
                    shared_ptr<Node> prevNode = map.at(str[i]);
                    shared_ptr<Node> currNode = map.at(str[i])->next;
                    
                    if (end == currNode) // if accidently remove the end
                        end = prevNode;
                    
                    prevNode->next = currNode->next;
                    
                    if (currNode->next!=nullptr) // change next node's hash
                        map.at(currNode->next->val) = prevNode;
                    
                    map.at(str[i]) = nullptr;
                }
            }
        }
        
        return dummy->next->val;
    }
    
private:
    struct Node
    {
        char val;
        shared_ptr<Node> next;
        
        Node(char val)
        {
            this->val = val;
        }
    };
    
    
};