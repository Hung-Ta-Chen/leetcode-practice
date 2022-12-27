/*
The entire process is very similiar to the process of merging in mergesort.
we use i to indicate the index in list1, use j to indicate the index in list2.
we keep the index of interval whose ending time is later, while increment the other index by 1. (move to the next interval)

3 cases (let interval 1 ends earlier than interval 2):
(1)  (the starting time of i2 <= the starting time of i1) => intersect
interval 1:         ||||||||||||    
interval 2:       |||||||||||||||||||||

(2)  (the starting time of i1 < the starting time of i2 <= the ending time of i1) => intersect
interval 1:         ||||||||||||    
interval 2:                ||||||||||||||

(3)  (the ending time of i1 < the starting time of i2) => no intersect
interval 1:         ||||||   
interval 2:                   ||||||||||||
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> intersect;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            if(firstList[i][1] < secondList[j][1]){
                if(secondList[j][0] <= firstList[i][0]){
                    vector<int> temp{firstList[i][0], firstList[i][1]};
                    intersect.push_back(temp);
                }
                else if(firstList[i][0] < secondList[j][0] && secondList[j][0] <= firstList[i][1]){
                    vector<int> temp{secondList[j][0], firstList[i][1]};
                    intersect.push_back(temp);
                }
                i++;
            }
            else{
                if(firstList[i][0] <= secondList[j][0]){
                    vector<int> temp{secondList[j][0], secondList[j][1]};
                    intersect.push_back(temp);
                }
                else if(secondList[j][0] < firstList[i][0] && firstList[i][0] <= secondList[j][1]){
                    vector<int> temp{firstList[i][0], secondList[j][1]};
                    intersect.push_back(temp);
                }
                j++;
            }
        }
        return intersect;
    }
};
