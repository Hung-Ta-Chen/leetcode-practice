/*
<< core concept >>
|10| 3| 5| 2| 6|
  l           r

if k = 120,
We fix 'r' and move 'l' forward to find the longest substring containing 'r' whose product is less than 120.
In this case, it's (5, 2, 6) => product=60

|10| 3| 5| 2| 6|
        l     r

And all substrings containing 'r' in this max substring have product less than 120 ((5, 2, 6), (2, 6), (6))
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int product = 1;
        int left, right;
        for(left = 0, right = 0; right < nums.size(); right++){
            product *= nums[right];
            while(product >= k && left < right){
                product /= nums[left++];
            }
            // In case that the single element is still larger than k
            if(product < k) count += (right - left + 1); 
        }
        return count;
    }
};
