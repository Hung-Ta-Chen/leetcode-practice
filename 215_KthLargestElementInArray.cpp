class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());  // Make the vector a heap
        
        // Remove k-1 largest numbers, then the root of heap will be kth largest number
        for(int i = 0; i < k-1; i++){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }        
        return nums.front();
    }
};