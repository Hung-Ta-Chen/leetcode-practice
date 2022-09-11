class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        map<char, char> table = {{')','('}, {']','['}, {'}', '{'}};
        
        for(auto iter = s.begin(); iter != s.end(); iter++){
            if(*iter == '(' || *iter == '[' || *iter == '{'){  // If read left bracket. push it in stack
                char_stack.push(*iter);
            }
            else{       // If read right bracket, return false if no corresponding left bracket
                if(char_stack.empty())   // If empty stack, return false
                    return false;
                if(char_stack.top() != table[*iter])  // If wrong left bracket, return false
                    return false;
                
                char_stack.pop();      // If there's correct left bracket, pop it   
            }
        }
        
        return char_stack.empty();  // If nothing left in stack, return true
    }
};