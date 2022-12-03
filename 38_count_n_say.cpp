class Solution {
public:
    string countAndSay(int n) {
        vector<pair<char, int>> count;
        string say = "1";
        // Repeat n-1 times
        for(int i = 0; i < n-1; i++){
            // Traverse "say" string and store the repeated substring in a vector
            int j = 0, cnt = 1;
            while(j < say.size()-1){
                if(say[j] == say[j+1])
                    cnt++;
                else{
                    count.push_back(pair<char, int>(say[j], cnt));
                    cnt = 1;
                }
                j++;
            }
            count.push_back(pair<char, int>(say[say.size()-1], cnt));
            // Construct the new "say" string
            say.clear();
            for(int k = 0; k < count.size(); k++){
                say.push_back('0' + count[k].second);
                say.push_back(count[k].first);                
            }
            count.clear();
        }
        return say;
    }
};
