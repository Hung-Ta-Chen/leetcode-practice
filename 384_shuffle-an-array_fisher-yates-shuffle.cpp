/*
Fisher-yates shuffle

[1   2   3   4   5]   (we choose a random num from 0 to 4, suppose 2, we swap the num at index 2 and at index 4)

[1   2   5   4 | 3]   (we choose a random num from 0 to 3, suppose 0, we swap the num at index 0 and at index 3)

[4   2   5 | 1   3]   (we choose a random num from 0 to 2, suppose 0, we swap the num at index 0 and at index 2)

[5   2 | 4   1   3]   (we choose a random num from 0 to 1, suppose 1, we swap the num at index 1 and at index 1)

[5 | 2   4   1   3]
*/
class Solution {
public:
    vector<int> vec;

    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    vector<int> reset() {
        return  vec;
    }
    
    vector<int> shuffle() {
        vector<int> shuf(vec.begin(), vec.end());
        for(int i = shuf.size()-1; i >= 1; i--){
            swap(shuf[i], shuf[rand() % (i+1)]);
        }
        return shuf;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
