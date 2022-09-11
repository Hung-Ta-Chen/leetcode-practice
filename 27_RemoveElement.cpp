class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator iter = nums.begin();
        
        while(iter != nums.end()){
            if(*iter == val)
                nums.erase(iter);  //Following nodes in vector will automatically move forward
                                   //So no need to change iter
            else
                iter++;
        }      
        return nums.size();
    }
};