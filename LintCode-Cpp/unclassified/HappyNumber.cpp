bool isHappy(int n)
{
    unordered_set<int> nums;
    int curr = n;
    while(nums.find(curr) == nums.end()) // chance of overflow if inf non-repeated sequences
    {
        nums.insert(curr);
        curr = getNum(curr);
    }

    return curr == 1;
}

int getNum(int n)
{
    int result = 0;
    while(n > 0)
    {
        int digit = n % 10;
        result += digit * digit;  
        n = n / 10;
    }
    return result;
}
// 1234 % 10 = 4
// 1234 / 10 = 123
// 123 % 10 = 3
// 123 / 10 = 12
//..