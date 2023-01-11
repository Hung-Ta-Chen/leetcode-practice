/*
1. When bitwise ANDing integers, only the position where all integers has a set bit will be set.
2. Since we are bitwise ANDing several continuous integers, all-set positions only appear in common prefix.
=> The essence of this problem is to find the common prefix of two number, and then pad the remaining bits with 0.

We keep right-shifting both integers until they are the same. 
Then we left-shift the integer exactly the same times we right-shift it to get the common prefix.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int l_shift = 0;
        while(left != right){
            left = left >> 1;
            right = right >> 1;
            l_shift++;
        }
        return left << l_shift;
    }
};
