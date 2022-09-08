/*
 *    Observe the zigzag: (n for numRows)
 *
 *    0 <-----(2n-2)----->     2n-2
 *    1 <----(2n-4)----> 2n-3  2n-1
 *    2 <---(2n-6)---> 2n-4    2n
 *    3 <--(2n-8)--> 2n-5      .
 *    .             .          .
 *    .           .            .
 *    .         .
 *  n-2 <-2--> n
 *  n-1
 *
 *  => We can divide the string into groups of 2n-2 characters, and each group has n rows.
 *  => First & last row only have one chars per group, while the others have two chars.
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        
        string zig("");
        int start;
        
        for(int row = 0; row <= numRows - 1; row++){    //We go row by row    
            /* In each row, we go group by group 
             * Remember to include the remaining chars as the last group 
             */
            for(int g = 0; g <= s.size() / (2*numRows-2); g++){  
                start = (2*numRows-2)*g;

                if(start + row >= s.size())   //Check if the index is out of range
                    continue;
                
                if(row == 0 || row == numRows - 1){  
                    zig.push_back(s[start + row]);
                }
                else{    
                    zig.push_back(s[start + row]);
                    if(start + row + 2*numRows-2-2*row < s.size())   //Check if the index is out of range
                        zig.push_back(s[start + row + 2*numRows-2-2*row]);
                }              
            }
        }
        return zig;
    }
};