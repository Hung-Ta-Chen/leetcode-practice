class Solution {
public:
    int mySqrt(int x) {  
        if(x == 0)
            return 0;
        
        int sqrt = 1;
        while(sqrt * sqrt <= x){
            if(sqrt * sqrt == x)
                return sqrt;           
            sqrt++;
            
            // Handle INT_MAX
            if(sqrt > 46340)
                return 46340;
        }        
        return sqrt - 1;
    }
};