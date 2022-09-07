class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto front = s.begin(),
             back = s.begin();
 
        unordered_map<char, string::iterator> char_table;   //Save the position of char in table this time (vs SlideWin1)
                                                            //so that FORWARD won't have to move char by char
        int max_len = 0;
        
        while(front < s.end() && back < s.end()){   
            if(char_table.find(*back) == char_table.end()){  //When the current char is not in the table
                char_table.insert(pair<char, string::iterator>(*back, back));
                back += 1;
                max_len = max(max_len, static_cast<int>(back - front));
            }
            else{        //When the current char is in the table   
                if(char_table[*back] < front){     //The position of repeat char is before FORWARD
                                                   //=> the repeat does not happen in Slide Window
                                                   //=> BACK can keep moving
                    char_table[*back] = back;
                    back += 1;
                    max_len = max(max_len, static_cast<int>(back - front));
                }
                else{                              //Repeat happens 
                                                   //=> FORWARD move forward to the next char of the repeated char 
                    front = char_table[*back] + 1;
                }
            }
        }
        
        return max_len;
    }
};