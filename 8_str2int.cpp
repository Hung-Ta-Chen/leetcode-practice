class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        string int_max{"2147483647"};
        
        // Find the range of digits
        int start = -1;  // Starting pos
        int end = -1;   // Ending pos

        // Handle Special cases
        if(s.length() == 0)    // Empty string is illegal
            return 0;
        else if(s.length() == 1){   // String only has one char
            if(isdigit(s[0]))
                return static_cast<int>(s[0]) - 48;
            else
                return 0;
        } 

        // General case
        for(auto iter = s.begin(); iter != s.end(); iter++){  // Iterate through the loop
            // Find starting pos first
            if(start == -1){     // If start pos is not found
                if(iter != s.end()-1){  // Not at the tail of the string yet
                    if(!isdigit(*(iter))){
                        if(*(iter) == ' '){
                            if(isdigit(*(iter+1))){  // If the next char of space is digit, start pos found
                                start = iter - s.begin() + 1;
                                continue;
                            }   
                            // If not, just continue
                        }    
                        else if(*(iter) == '+'||*(iter) == '-'){
                            if(isdigit(*(iter+1))){   // Sign is illegal only when next char is digit
                                start = iter - s.begin() + 1;   // Start pos found
                                continue;
                            }                        
                            else
                                return 0;
                        }
                        else
                            return 0;  // Other type of char are all illegal
                    }
                    else{   //If char is digit, starting pos found
                        start = iter - s.begin();
                        continue;
                    }
                }
                else{  // At tail
                    if(isdigit(*iter)){
                        start = iter - s.begin();
                        end = iter - s.begin();
                        break;
                    }
                    else
                        return 0; 
                }
            }
            else{   // Starting pos is found, then start find ending pos
                if(end == -1){    // End pos is not found yet
                    if(!isdigit(*(iter))){    // The char is not digit => the previos char is end pos
                        end = iter - s.begin()-1;
                        break;
                    }
                    else{    // The char is digit
                        if(iter != s.end()-1){ // Not tail
                            continue;
                        }
                        else{ // At tail
                            end = s.length()-1;   
                        }
                    }
                }
            }
        }
        
        
        // Truncate zero streak at the beginning of the string
        auto iter1 = s.begin()+start;
        int origin_start = start;
        while(*iter1 == '0'){
            iter1++;
            
            if(iter1 > s.begin()+end) // All digits are 0
                return 0;
        }
        start = iter1 - s.begin();
        
        // Find sign
        if(origin_start > 0){
            if(s[origin_start - 1] == '-')
                sign = -1;
        }

        // Handle overflow by comparing the string of MAX_INT digit
        if(end - start + 1 > 10){
            if(sign == -1)
                return INT_MIN;
            else
                return INT_MAX; 
        }
        else if(end - start + 1 == 10){
            for(int i = 0; i < 10; i++){
                if(s[start+i] < int_max[i])
                    break;
                else if(s[start+i] == int_max[i])
                    continue;
                else{
                    if(sign == -1)
                        return INT_MIN;
                    else
                        return INT_MAX;
                }      
            }
        }
        
        // Calculate the sum of digits
        auto iter = s.begin() + start;
        do{
            result *= 10;
            result += static_cast<int>(*iter) - 48;
            iter++;
        }
        while(iter != s.begin() + end + 1);
   
        return (sign > 0)?result:result*(-1);         
    }
};