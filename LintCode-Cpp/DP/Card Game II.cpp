/* 
1538. Card Game II

You are playing a card game with your friends, there are n cards in total. Each card costs cost[i] and inflicts damage[i] damage to the opponent. You have a total of totalMoney dollars and need to inflict at least totalDamage damage to win. And Each card can only be used once. Determine if you can win the game.

Example
Example1

Input:
cost = [1,2,3,4,5]
damage = [1,2,3,4,5]
totalMoney = 10
totalDamage = 10

Output: true
Explanation: We can use the [1,4,5] to cause 10 damage, which costs 10.
Example2

Input:
cost = [1,2]
damage = [3,4]
totalMoney = 10
totalDamage = 10

Output: false
Explanation: We can only cause 7 damage at most.

*/

class Solution {
public:
    /**
     * @param cost: costs of all cards
     * @param damage: damage of all cards
     * @param totalMoney: total of money
     * @param totalDamage: the damage you need to inflict
     * @return: Determine if you can win the game
     */
    bool cardGame(vector<int> &cost, vector<int> &damage, int totalMoney, int totalDamage) {
        vector<int> prevMaxDamage(totalMoney + 1, 0);
        for(int i = cost[0]; i <= totalMoney; i++)
        {
            prevMaxDamage[i] = damage[0]; 
        }
        
        for(int i = 1; i < cost.size(); i++)
        {
            // we can choose it if cost[i] <= totalMoney
            // otherwise proceed with the prevRow's result since it is not chosen
            // it needs to be j-- to ensure we are computing based previous row
            // rather than the new computed value
            for(int j = totalMoney; j >= cost[i]; j--)
            {
                prevMaxDamage[j] = max(prevMaxDamage[j], damage[i] + prevMaxDamage[j - cost[i]]);
            }
        }
        
        return prevMaxDamage.back() >= totalDamage;
    }
};

// Sol1 Brutal Force: find all combinations
// O(2^n)

// Sol2: DP
// if choosing n as the length of the array:
// f[n] is the max damage within the totalMoney
// then f[n] = max(choosing item n, not chooseing item n: f[n-1])
// choosing item n means we need to compute f[n-1] for totalMoney - cost[n]
// so we need to compute a 2D array for f[n, totalMoney]

// *optimization*
// however, since each new row in the 2D array only depends on the previous row
// then essentially we only need one row to record the previous result
// and record new result based on the previous result