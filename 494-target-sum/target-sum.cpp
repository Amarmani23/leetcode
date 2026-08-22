class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        return rec(nums,0,0,target);
    }
private:
    int rec(vector<int>& nums,int sum,int idx,int &target){
        if(idx==nums.size()){
            return sum == target ? 1:0;
        }
        int pos=rec(nums,sum+nums[idx],idx+1,target);
        int neg = rec(nums,sum-nums[idx],idx+1,target);
        return pos+neg;
    }
};