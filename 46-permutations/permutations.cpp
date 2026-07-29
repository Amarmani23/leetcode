class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        vector<bool> visited(nums.size(),false);
        backtrack( nums, result,curr,0,visited);
        return result;
    }
private:
    void backtrack(vector<int>& nums,vector<vector<int>> &result,vector<int> curr,int index, vector<bool>& visited){
        if(curr.size()==nums.size()){
            result.push_back(curr);
            return;
        }
        for(int i=index;i<nums.size();++i){
            if(visited[i]) continue;

            visited[i]=true;
            curr.push_back(nums[i]);
            backtrack( nums, result,curr,0,visited);
            curr.pop_back();
            visited[i]=false;
            
        }
    }
};