class Solution {
public:
    void kSum(vector<vector<int>>& ans, vector<int>& find, vector<int>& nums, int start, int k, int target){
        int n = nums.size();
        int sum;
        //cout <<start<<" "<<k<<" "<<target << endl;
        if (k == 2){  // Base case
            int ptr1 = start, ptr2 = n - 1;
            while(ptr2 > ptr1){
                if(ptr1 > start && nums[ptr1] == nums[ptr1 - 1]){
                    ptr1++;
                    continue;
                }
                if(ptr2 < n-1 && nums[ptr2] == nums[ptr2 + 1]){
                    ptr2--;
                    continue;
                }
      
                sum = nums[ptr1] + nums[ptr2];
                //cout << nums[ptr1] <<" "<<nums[ptr2]<<" "<<sum<<" "<<target<<endl;
                if(sum < target) ptr1++;
                else if(sum > target) ptr2--;
                else{
                    find.push_back(nums[ptr1++]);
                    find.push_back(nums[ptr2--]);
                    ans.push_back(find);
                    find.pop_back();
                    find.pop_back();
                }
            }
        }
        else{
            for(int ptr = start; ptr <= n - k; ptr++){
                if(ptr > start && nums[ptr] == nums[ptr - 1]) continue;
                
                sum = 0;
                for(int i = ptr; i < ptr+k; i++) sum+=nums[i];
                if(sum > target) break;
                
                sum = nums[ptr];
                for(int i = n-1; i > n-k; i--) sum+=nums[i];
                if(sum < target) continue;
                
                sum = nums[ptr];
                find.push_back(nums[ptr]);
                kSum(ans, find, nums, ptr+1, k-1, target - sum);
                find.pop_back();
            }
        }
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;       
        sort(nums.begin(), nums.end());
        vector<int> find;
        
        kSum(result, find, nums, 0, 4, target);
        
        return result;
    }
};