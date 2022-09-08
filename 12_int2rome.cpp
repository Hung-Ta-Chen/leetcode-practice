class Solution {
public:
    string intToRoman(int num) {
        // Construct the hash table(key: number, val: rome)
        map<int, string> rome_table;
        map<int, string>::iterator iter;
        rome_table.insert(pair<int, string>(1, "I"));
        rome_table.insert(pair<int, string>(5, "V"));
        rome_table.insert(pair<int, string>(10, "X"));
        rome_table.insert(pair<int, string>(50, "L"));
        rome_table.insert(pair<int, string>(100, "C"));
        rome_table.insert(pair<int, string>(500, "D"));
        rome_table.insert(pair<int, string>(1000, "M"));
        
        rome_table.insert(pair<int, string>(4, "IV"));
        rome_table.insert(pair<int, string>(9, "IX"));
        rome_table.insert(pair<int, string>(40, "XL"));
        rome_table.insert(pair<int, string>(90, "XC"));
        rome_table.insert(pair<int, string>(400, "CD"));
        rome_table.insert(pair<int, string>(900, "CM"));
        
        vector<int> list{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        
        string s("");
        for(int i = 0; i < list.size(); i++){
            iter = rome_table.find(list[i]);
            
            while(num >= list[i]){
                s.append(iter->second);
                num -= list[i];
            }
        }
        
        return s;
    }
};