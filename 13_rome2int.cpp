class Solution {
public:
    int romanToInt(string s) {
        // Construct the hash table (key: rome, val: number)
        map<char, int> rome_table;
        map<char, int>::iterator iter;
        rome_table.insert(pair<char, int>('I', 1));
        rome_table.insert(pair<char, int>('V', 5));
        rome_table.insert(pair<char, int>('X', 10));
        rome_table.insert(pair<char, int>('L', 50));
        rome_table.insert(pair<char, int>('C', 100));
        rome_table.insert(pair<char, int>('D', 500));
        rome_table.insert(pair<char, int>('M', 1000));
        
        int num = 0;
        for(int i = 0; i < s.length() - 1; i++){
            iter = rome_table.find(s[i]);       
            int flag = 1;   // (1: plus, -1: minus)
            
            // Check if there's special subtraction case
            if (s[i] == 'I'){
                if (s[i+1] == 'V' || s[i+1] == 'X')
                    flag = -1;
            }
            if (s[i] == 'X'){
                if (s[i+1] == 'L' || s[i+1] == 'C')
                    flag = -1;
            }
            if (s[i] == 'C'){
                if (s[i+1] == 'D' || s[i+1] == 'M')
                    flag = -1;
            }
            
            num = num + flag * iter->second;
        }
        iter = rome_table.find(s[s.length() - 1]);
        num += iter->second;
        
        return num;
    }
};