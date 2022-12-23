class Solution {
public:
    bool isHappy(int n) {
        set<int> tried_num;
        int sum = n;
        int num, res;
        while(sum != 1){
            // Check if we reach repeated number
            // If repeated, return false
            if(tried_num.find(sum) != tried_num.end()) return false;
            // If not, put it in hash
            tried_num.insert(sum);
            num = sum;
            sum = 0;
            while(num != 0){
                res = num % 10;
                num = num / 10;
                sum += (res * res);
            }
        }
        return true;
    }
};
