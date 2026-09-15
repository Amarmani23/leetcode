class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int>result;
        for(int i =0;i<expression.length();i++){
            char curr_char=expression[i];
            if(curr_char== '+'  || curr_char== '-' || curr_char == '*'){
                string left_sub_expres=expression.substr(0,i);
                string right_sub_expres=expression.substr(i+1);
                
                vector<int> left_result=diffWaysToCompute(left_sub_expres);
                vector<int> right_result=diffWaysToCompute(right_sub_expres);

                for(int left: left_result){
                    for(int right : right_result){
                        if(curr_char =='+'){
                            result.push_back(left+right);
                        }
                        else if(curr_char =='-'){
                            result.push_back(left-right);
                        }
                        else if(curr_char =='*'){
                            result.push_back(left*right);
                        }
                    }
                }
            }

        }
        if(result.empty()){
            result.push_back(stoi(expression));

        }
        return result;
    }
};