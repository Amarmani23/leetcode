class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<vector<int>> result;
        // vector<int> curr;
        // vector<bool> visited(nums.size(),false);
        // backtrack( nums, result,curr,visited);
        // return result;

        //another method by swaping

        vector<vector<int>> result;
        backtrack(nums,result,0);
        return result;
        
    }
private:
    // void backtrack(vector<int>& nums,vector<vector<int>> &result,vector<int> curr, vector<bool>& visited){
    //     if(curr.size()==nums.size()){
    //         result.push_back(curr);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();++i){
    //         if(visited[i]) continue;

    //         visited[i]=true;
    //         curr.push_back(nums[i]);
    //         backtrack( nums, result,curr,visited);
    //         curr.pop_back();
    //         visited[i]=false;
            
    //     }
    // }

    void backtrack(vector<int>& nums,vector<vector<int>> &result,int index){
        if(index==nums.size()){
            result.push_back({nums});
            return;
        }
        for(int i=index;i<nums.size();++i){
        swap(nums[index],nums[i]);
        backtrack(nums,result,index+1);
        swap(nums[i],nums[index]);

        }
    }
};