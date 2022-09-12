class Solution {
public:
    string addBinary(string a, string b) {
        string sum_str = "";
        auto iter_a = a.rbegin();
        auto iter_b = b.rbegin();
        int flag = 0;  // For carry
        int sum;
        
        while(iter_a != a.rend() && iter_b != b.rend()){
            sum = (*iter_a - '0') + (*iter_b - '0') + flag;
            
            if(sum > 1){
                flag = sum / 2;
                sum = sum - 2;
            }
            else
                flag = 0;
            
            sum_str.insert(sum_str.begin(), sum + '0');
            iter_a++;
            iter_b++;
        }
        
        while(iter_a != a.rend()){
            sum = (*iter_a - '0') + flag;

            if(sum > 1){
                flag = sum / 2;
                sum = sum - 2;
            }
            else
                flag = 0;

            sum_str.insert(sum_str.begin(), sum + '0');
            iter_a++;
        }
        while(iter_b != b.rend()){
            sum = (*iter_b - '0') + flag;

            if(sum > 1){
                flag = sum / 2;
                sum = sum - 2;
            }
            else
                flag = 0;

            sum_str.insert(sum_str.begin(), sum + '0');
            iter_b++;
        }
        
        if(flag) sum_str.insert(sum_str.begin(), flag + '0');
        
        return sum_str;      
    }
};