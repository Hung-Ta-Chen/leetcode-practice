/*
Since the area is only decided by minimum of two sides and the distance,
we change the smaller side by moving the pointer inward to see if the new area is larger.
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size()-1;
        int max_area = 0;
        while(low <= high){
            max_area = max(max_area, min(height[low], height[high]) * (high - low));
            if(height[low] <= height[high]) low++;
            else high--;
        }
        return max_area;
    }
};
