/*
Use hashmaps for anagram problem
(If only alphabets involved, can use vector as well)
*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()) return ans;

        map<char, int> p_hashmap, s_hashmap;
        // Construct hashmap for p
        for(int i = 0; i < p.size(); i++){
            if(p_hashmap.find(p[i]) == p_hashmap.end()) p_hashmap[p[i]] = 1;
            else p_hashmap[p[i]] += 1;
        }
        int low = 0, high = p.size()-1;
        // Construct hashmap for s
        for(int i = 0; i < p.size(); i++){
            if(s_hashmap.find(s[i]) == s_hashmap.end()) s_hashmap[s[i]] = 1;
            else s_hashmap[s[i]] += 1;
        }
        if(s_hashmap == p_hashmap) ans.push_back(low);
        // Move the sliding window forward by 1 element in each iteration
        // then compare the hashmaps
        while(high < s.size()-1){
            if(s_hashmap[s[low]] == 1) s_hashmap.erase(s[low]);
            else s_hashmap[s[low]]--;
            low++;
            high++;
            if(s_hashmap.find(s[high]) == s_hashmap.end()) s_hashmap[s[high]] = 1;
            else s_hashmap[s[high]] += 1;
            if(s_hashmap == p_hashmap) ans.push_back(low);
        }
        return ans;
    }
};
