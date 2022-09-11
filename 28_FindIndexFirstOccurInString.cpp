class Solution {
public:
    int strStr(string haystack, string needle) {
        string::iterator h_iter;
        
        for(h_iter = haystack.begin(); h_iter != haystack.end(); h_iter++){
            if(*h_iter == needle[0]){
                bool flag = true;
                
                for(int i = 0; i < needle.length(); i++){
                    if (*(h_iter+i) != needle[i]){
                        flag = false;
                        break;
                    }
                }
                if(flag) 
                    return h_iter - haystack.begin();
            }
        } 
        return -1;
    }
};