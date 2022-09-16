class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";  //Return 0 if one of them is 0
        
        string strProduct("0");
        int product;
        int carry = 0;
        for(int i2 = 0; i2 < num2.size(); i2++){
            string temp("");
            carry = 0;
            for(int i1 = num1.size()-1; i1 >= 0; i1--){
                product = (char2int(num2[i2]) * char2int(num1[i1])) + carry;
                carry = product / 10;
                product %= 10;
                temp.insert(0, 1, int2char(product));
            }
            if(carry != 0) temp.insert(0, 1, int2char(carry));
            
            for(int k = 0; k < num2.size()-1-i2; k++){
                temp.push_back('0');    //補0
            } 
            strProduct = strPlus(strProduct, temp);      //加上去   
        }
        
        return strProduct;
    }
    
    string strPlus(string str1, string str2){
        if(str1 == "0") return str2;
        if(str2 == "0") return str1;
        
        int i = str1.size()-1, j = str2.size()-1;
        string strSum("");
        int sum;
        int carry = 0;
        
        while(i >= 0 && j >= 0){
            sum = char2int(str1[i--]) + char2int(str2[j--]) + carry;
            carry = sum / 10;
            sum %= 10;
            strSum.insert(0, 1, int2char(sum));
        }
        
        while(i >= 0){
            sum = char2int(str1[i--]) + carry;
            carry = sum / 10;
            sum %= 10;
            strSum.insert(0, 1, int2char(sum));
        }
        
        while(j >= 0){
            sum = char2int(str2[j--]) + carry;
            carry = sum / 10;
            sum %= 10;
            strSum.insert(0, 1, int2char(sum));
        }
        
        if(carry == 1) strSum.insert(0, 1, int2char(carry));
        return strSum;
    }
    
    int char2int(char c){
        return c - '0';
    }
    
    char int2char(int digit){
        return '0' + digit;
    }
};