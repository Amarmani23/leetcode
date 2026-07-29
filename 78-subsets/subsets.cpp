class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(nums,result,0,curr);
        return result;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& result,int index,vector<int> &curr){
        result.push_back(curr);
        for(int i=index;i<nums.size();i++){
            curr.push_back(nums[i]);
            backtrack(nums,result,i+1,curr);
            curr.pop_back();
        }
    }
};