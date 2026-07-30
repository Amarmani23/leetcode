class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>curr;
        backtrack(candidates,result,curr,target,0);
        return result;
    }
    int sum(vector<int>&nums){
        int s=0;
        for(auto num:nums){
            s+=num;
        }
        return s;
    }
private:
    void backtrack(vector<int>& candidates,vector<vector<int>> &result,vector<int>&curr,int target,int index){
       
        if(sum(curr) == target){
            result.push_back(curr);
            return;
        }
        for(int i= index;i<candidates.size();++i){
            if(sum(curr)<target){
                curr.push_back(candidates[i]);
                backtrack(candidates,result,curr,target,i);
                curr.pop_back();
            }

        }
    }
};