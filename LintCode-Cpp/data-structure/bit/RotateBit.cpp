/* 
723. Rotate Bits - Left
Bit Rotation -—— A rotation (or circular shift) is an operation similar to shift except that the bits that fall off at one end are put back to the other end.

In left rotation, the bits that fall off at left end are put back at right end.

Let n is stored using 8 bits. Left rotation of n = 　11100101 by 3 makes n = 00101111 (Left shifted by 3 and first 3 bits are put back in last ). If n is stored using 16 bits or 32 bits then left rotation of n (000…11100101) becomes 00..0011100101000.

In this problem, you can assume that n was stored in 32 Bits

Example
Given n = 123, d = 4
return 183
*/

class Solution {
public:
    /**
     * @param n: a number
     * @param d: digit needed to be rorated
     * @return: a number
     */
    int leftRotate(int n, int d) {
    /*
        if (d == 0 || d >= 32) return n;
        
        // conversion
        vector<int> bits(32, 0);
        int cnt(31);
        while( n > 0 && cnt >=0)
        {
            bits[cnt] = n%2;
            cnt--;
            n = n / 2;
        }
        

        // rotation: left half
        int result = 0;
        int weight = 1;
        
        cnt = d - 1;
        while(cnt >= 0)
        {
            result += weight * bits[cnt];
            weight = weight * 2;
            cnt--;
        }
        
        // rotation: right half
        cnt = 31;
        while(cnt >= d)
        {
            result += weight * bits[cnt];
            weight = weight * 2;
            cnt--;
        }
        
        return result;
    */
     return (n >> (32 - d)) + (n << d); // bit manipulation
    }

};

// we convert the int into an 32-size array
// keep % 2 and / 2

// when rotate bits, partition the array into left and right half
// recover the number by reading from left half first

