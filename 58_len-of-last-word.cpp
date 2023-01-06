class Solution {
public:
    int lengthOfLastWord(string s) {
        auto tail = s.rend();
        auto head = s.rend();
        for(string::reverse_iterator iter = s.rbegin(); iter < s.rend(); iter++){
            if(tail == s.rend()){  // The tail of word not found yet
                if(*iter != ' ')   // First non-space char => tail 
                    tail = iter;    
            }
            else{           
                if(head == s.rend()){ // Tail of the word found, but head not found yet
                    if(*iter == ' '){ // First non-char space => prev char is head
                        head = iter - 1;
                    }
                }
            }
        }        
        // When the head of the word is also the head of the string
        if(tail != s.rend() && head == s.rend())
            head = s.rend() - 1;
        
        return head - tail + 1;        
    }
};
