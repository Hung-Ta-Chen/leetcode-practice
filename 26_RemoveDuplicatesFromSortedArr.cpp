class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        
        int first = -101;
        while(iter != nums.end()){
            if (*iter != first){
                first = *iter;
                iter++;
            }
            else{
                // 當一vector的一element被erase,後面剩下的elements會往前補上memory
                // 因此erase之後iter不用往後移
                nums.erase(iter);
            }
        }        
        return nums.size();        
    }
};