class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>> suffix_sets(26, unordered_set<string>());
        // Grouping all the suffices by the starting letter of the string
        for(int i = 0; i < ideas.size(); i++){
            suffix_sets[ideas[i][0]-'a'].insert(ideas[i].substr(1, ideas[i].size()-1));
        }
        // Check the non-intersect part of each pair of string
        long long name_count = 0;
        for(int i = 0; i < 25; i++){
            for(int j = i+1; j < 26; j++){
                int mutual_count = 0;
                for(auto s: suffix_sets[i]){
                    if(suffix_sets[j].find(s) != suffix_sets[j].end())
                        mutual_count++;
                }
                name_count += 2 * (suffix_sets[i].size()-mutual_count) * (suffix_sets[j].size()-mutual_count);
            }
        }
        return name_count;
    }
};
