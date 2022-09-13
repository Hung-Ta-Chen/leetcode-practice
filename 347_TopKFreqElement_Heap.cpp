class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int , int> freq;
        
        //Count the frequency and store it in hash table
        for(int i = 0; i < nums.size(); i++){
            if(freq.find(nums[i]) != freq.end())
                freq[nums[i]] += 1;
            else
                freq[nums[i]] = 1;
        }
        
        vector<pair<int, int>> vec;
        vector<int> ans;
        for(auto iter = freq.begin(); iter != freq.end(); iter++){
            vec.push_back(pair<int, int>(iter->second, iter->first));
        }
        
        make_heap(vec.begin(), vec.end());
        for(int j = 0; j < k; j++){
            ans.push_back(vec[0].second);
            pop_heap(vec.begin(), vec.end());
            vec.pop_back();
        }
        
        return ans;
    }
};