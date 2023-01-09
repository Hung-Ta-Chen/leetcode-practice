class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int, int>> memo(nums.size(), make_pair(1, 1)); // first: max length, second: cnt of max length
        int max_len = 0, max_count = 0;
        for(int i = 0; i < nums.size(); i++){ 
            for(int j = 0; j < i; j++){ 
                if(nums[j] < nums[i]){
                    if(memo[j].first + 1 == memo[i].first) memo[i].second += memo[j].second;  // As long as current longest subseq ended at i
                    else if(memo[j].first + 1 > memo[i].first){   // Longer than the current longest subseq ended at i
                        memo[i].first = memo[j].first + 1;
                        memo[i].second = memo[j].second;
                    }
                }
            }
            if(memo[i].first > max_len){     // Longer than the current longest subseq
                max_len = memo[i].first;
                max_count = memo[i].second;
            }
            else if(memo[i].first == max_len) max_count += memo[i].second;  // As long as current longest subseq
        }
        return max_count;
    }
};
