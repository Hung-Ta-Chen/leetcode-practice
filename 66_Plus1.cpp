class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int flag = 1;
        int sum;
        
        for(auto iter = digits.rbegin(); iter < digits.rend(); iter++){
            sum = *iter + flag;        
            flag = 0;
            if(sum >= 10){
                flag = sum / 10;
                sum = sum - 10;
            }  
            result.insert(result.begin(), sum);
        }
        
        if(flag != 0)
            result.insert(result.begin(), flag);
        
        return result;
    }
};