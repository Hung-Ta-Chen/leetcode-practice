class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int ,int>> temp;
        vector<string> prize(score.size(), "");  //Create a vec of str with length of n
        
        //Push the (score, position) in the the vec and make vec a heap
        for(int i = 0; i < score.size(); i++){
            temp.push_back(pair<int, int>(score[i], i));
        }
        make_heap(temp.begin(), temp.end(), Compare());
        
        //Iteratively pop out one with the largest score
        for(int i = 0; i < score.size(); i++){
            if(i == 0) prize[temp[0].second] = "Gold Medal";
            else if(i == 1) prize[temp[0].second] = "Silver Medal";
            else if(i == 2) prize[temp[0].second] = "Bronze Medal";
            else prize[temp[0].second] = to_string(i+1);
            
            pop_heap(temp.begin(), temp.end(), Compare());
            temp.pop_back();
        }     
        return prize;
    }
    
    class Compare{
    public:
        //Compare(){}
        int operator()(pair<int, int> a, pair<int, int> b){
          return a.first < b.first;
        }  
    };
};
