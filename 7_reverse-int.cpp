class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN) return 0;  //Handle INT_MIN first becuase we will multiply x by -1
        
        int reverse = 0;
        int temp = (x > 0)?x:(-1)*x;  
        
        while(temp != 0){
            if (reverse > INT_MAX / 10)  //Make sure reverse won't overflow after *10
                return 0;
            
            reverse *= 10;
            
            if (reverse > INT_MAX - temp % 10)  //Make sure reverse won't overflow after plus temp % 10
                return 0;
            
            reverse += temp % 10;
            temp /= 10;
        }
        
        return (x > 0)?reverse:(-1)*reverse;
    }
};