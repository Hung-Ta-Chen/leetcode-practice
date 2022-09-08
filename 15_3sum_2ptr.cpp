class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplet;   
        sort(nums.begin(), nums.end());  //Sort the vector first
        
        // 2-pointer algorithm
        int ptr1, ptr2;   // ptr1 for front pointer, ptr2 for back pointer
        for(int i = 0; i <= nums.size() - 3; i++){
            if(i > 0 && nums[i] == nums[i-1])      //If nums[i] is the same as the previous int
                continue;                          //Skip to the next int to avoid repetition 
            
            ptr1 = i + 1;
            ptr2 = nums.size() - 1;
            
            while(ptr1 != ptr2){
                if(ptr1 > i + 1 && nums[ptr1] == nums[ptr1-1]){  //If nums[ptr1] is the same as the previous int
                    ptr1++;                                      //Skip to the next int to avoid repetition 
                    continue;
                }
                if(ptr2 < nums.size() - 1 && nums[ptr2] == nums[ptr2+1]){  //If nums[ptr2] is the same as the previous int
                    ptr2--;                                                //Skip to the next int to avoid repetition 
                    continue;
                }
                    
                if(nums[ptr1] + nums[ptr2] < 0-nums[i]){  //If the sum of nums[ptr1]&nums[ptr2] is smaller than target 
                    ptr1++;                               //ptr1 move forward 1 element cuz the next element is larger
                }
                else if(nums[ptr1] + nums[ptr2] > 0-nums[i]){ //If the sum of nums[ptr1]&nums[ptr2] is larger than target
                    ptr2--;                                   //ptr2 move backward 1 element cuz the prev element is smaller
                }
                else{      //If the sum is equal to target, push the triplet into vec
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[ptr1]);
                    temp.push_back(nums[ptr2]);
                    triplet.push_back(temp);
                    ptr2--;   //Update one of the pointer to keep searching for another possible ans
                              //ptr1++ is fine as well
                }
            }   
        }  
        return triplet;   
    }
};