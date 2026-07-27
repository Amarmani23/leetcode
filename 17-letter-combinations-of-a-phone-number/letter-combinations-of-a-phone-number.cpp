class Solution {
public:
    const vector<string> phoneMap={
            "","", "abc","def","ghi",
            "jkl","mno","pqrs","tuv","wxyz"
    };
    void backtrack(const string& digits,int index,string &current,vector<string>&result){
        if(index==digits.length()){
            result.push_back(current);
            return;
        }

        string letter = phoneMap[digits[index]-'0'];

        for(char c:letter){
            current.push_back(c);
            backtrack(digits,index+1,current,result);
            current.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.empty()) return {};

        vector<string>result;
        string current="";
        backtrack(digits,0,current,result);
        return result;
    }
};