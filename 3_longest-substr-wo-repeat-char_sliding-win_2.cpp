/*
Use a hashmap to record the last index of a character
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> char_pos; // To record the last index of characters in substring
        int max_len = 0;
        int left, right;
        for(left = 0, right = 0; right < s.size(); right++){
            // We need max here because we don't want left to go backward when encountering a previously recorded character
            if(char_pos.find(s[right]) != char_pos.end()) left = max(left, char_pos[s[right]] + 1);
            max_len = max(max_len, right - left + 1);
            char_pos[s[right]] = right;
        }
        return max_len;
    }
};
