class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        auto front = s.begin(),
             back = s.begin();
        unordered_map<char, string::iterator> char_list;
        
        int max_len = 0;
        int current_len;
        
        while(front < s.end() && back < s.end()){
            char_list.clear();    // Clear the hash table every time, which is inefficient
            char_list.insert(pair<char, string::iterator>(*front, front));
            current_len = 1;

            // BACK go to the next char of FRONT every time a repeat char is found,
            // which is inefficient since BACK will have to re-visit some chars
            back = front + 1;    
            while(back < s.end() && char_list.find(*back) == char_list.end()){    
                char_list.insert(pair<char, string::iterator>(*back, back));
                current_len++;
                back++;
            }
            
            max_len = max(max_len, current_len);
            
            if (back < s.end()){
                front = char_list[*back] + 1;
            }
        }
        
        return max_len;
    }
};