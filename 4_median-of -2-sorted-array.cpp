class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int count = 0;
        
        vector<int>::iterator iter1 = nums1.begin();
        vector<int>::iterator iter2 = nums2.begin();

        // Merge two sorted array first
        // Both arrays are not finished
        while(iter1 != nums1.end() && iter2 != nums2.end()){
            if (*iter1 < *iter2){
                vec.push_back(*iter1);
                iter1++;
            }
            else{
                vec.push_back(*iter2);
                iter2++;
            }
            
            if (vec.size() ==  ((nums1.size() + nums2.size())/2+1)){
                if ((nums1.size() + nums2.size())%2 == 0)
                    return (static_cast<double>(vec[vec.size()-2])+(vec[vec.size()-1]))/2.0;
                else
                    return static_cast<double>(vec[vec.size()-1]);
            }
                
        }
        
        // Only 1 array remain
        while(iter1 != nums1.end()){
            vec.push_back(*iter1);
            iter1++;

            if (vec.size() ==  ((nums1.size() + nums2.size())/2+1)){
                break;
            }
        }
        
        while(iter2 != nums2.end()){
            vec.push_back(*iter2);
            iter2++;

            if (vec.size() ==  ((nums1.size() + nums2.size())/2+1)){
                break;
            }
        }
        
        if ((nums1.size() + nums2.size())%2 == 0)
            return (static_cast<double>(vec[vec.size()-2])+(vec[vec.size()-1]))/2.0;
        else
            return static_cast<double>(vec[vec.size()-1]);
                    
    }
};