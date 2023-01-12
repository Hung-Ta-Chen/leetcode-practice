/*
To solve this problem,
we iteratively fix a point, 
then connect this point with the other points and record the slope with a hash table.

Also, we can skip the pair of points which is already checked in previous iterations.
*/
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() == 1) return 1;
        int max_num = 1;
        for(int i = 0; i < points.size()-1; i++){
            map<double, int> hash;
            int x1 = points[i][0], y1 = points[i][1];
            for(int j = i+1; j < points.size(); j++){
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 == x2) hash[INT_MAX]++;
                else hash[(y2-y1)/(double)(x2-x1)]++;
            }
            int max = 1;
            for(auto iter = hash.begin(); iter != hash.end(); iter++){
                if(max < iter->second) max = iter->second;
            }
            if(max_num < max) max_num = max;
        }
        return max_num + 1;
    }
};
