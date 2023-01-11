/*
1. When bitwise ANDing integers, only the position where all integers has a set bit will be set.
2. Since we are bitwise ANDing several continuous integers, all-set positions only appear in common prefix.
=> The essence of this problem is to find the common prefix of two number, and then pad the remaining bits with 0.

<< Brian-Kernighan's algorithm >>
This algorithm can unset the lowest set bit in a integer.
We keep unsetting the lowest set bit of right until it's <= left,
which mean we only keeping the set bits appearing in both integers.
Therefore, we can find the common prefix in this way, then get the answer by bitwise ANDing them.
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right > left){
            right = right & (right - 1);
        }
        return left & right;
    }
};
