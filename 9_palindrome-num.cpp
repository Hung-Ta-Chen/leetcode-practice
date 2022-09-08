class Solution {
public:
    bool isPalindrome(int x) {
        // Negative int cannot be palindrome
        if(x<0) return false;     
        if(x == 0) return true;
    
        vector<int> arr;  // Use vector to store digits of the number
        
        while(x > 0){
            arr.push_back(x % 10);
            x /= 10;
        }
        
        for(int i = 0; i <= arr.size() / 2; i++){
            if(arr[i] != arr[arr.size()-i-1]) 
                return false;       
        }

        return true;
    }
};