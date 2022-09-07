class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto front = s.begin(),
             back = s.begin();
        unordered_set<char> char_table;
        
        int max_len = 0;
        
        while(front < s.end() && back < s.end()){
            if(char_table.find(*back) == char_table.end()){  //char not in table
                char_table.insert(*back);
                back += 1;  //BACK move forward one
                max_len = max(max_len, static_cast<int>(back - front));
            }
            else{     
                /*char in table => repeat
                  move FRONT forward by one char and remove it from table every time 
                  until the current char is no longer in the table*/
                char_table.erase(*front);
                front += 1;
            }
        }
        
        return max_len;
    }
};
