class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combination;
        if(digits.size()==0){ combination.push_back("");return combination;}
        string map[8] = {"abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>last=letterCombinations(digits.substr(1));
        for (int i=0;i<last.size();i++){
            for(int j=0;j<map[digits[0]-'2'].size();j++){
                combination.push_back(map[digits[0]-'2'][j]+last[i]);
            }
        }    
        return combination;
    }
};
