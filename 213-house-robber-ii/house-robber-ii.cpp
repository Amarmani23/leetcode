class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        return max(solve(0,nums.size()-2,nums),solve(1,nums.size()-1,nums));
        
    }
private:
    int solve(int start,int end,vector<int>&nums){
        int prev1=nums[start];
        int prev2=max(nums[start],nums[start+1]);
        int result=prev2;
        for(int i=start+2;i<=end;i++){
            result=max(prev2,prev1+nums[i]);
            prev1=prev2;
            prev2=result;
        }
        return result;
    }
};