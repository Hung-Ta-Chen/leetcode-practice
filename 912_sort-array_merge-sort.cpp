class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() == 1) 
            return nums;        
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void mergeSort(vector<int>& arr, int start, int end){
        if(start == end) 
            return;
        int mid = (start+end)/2;  // Midpoint
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
    
    // Merge two sorted subarrays
    void merge(vector<int>& arr, int start, int mid, int end){
        int i = start;
        int j = mid+1;
        // Allocate a fixed-size memory save a lot of time 
        // in comparison with using "push_back()"
        vector<int> temp(end-start+1, 0);
        int k = 0;
        while(i <= mid && j <= end){
            if(arr[i] < arr[j])
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }        
        while(i <= mid) 
            temp[k++] = arr[i++];        
        while(j <= end)
            temp[k++] = arr[j++];      
        for(int k = 0; k < end-start+1; k++)
            arr[start+k] = temp[k];
    }
};
