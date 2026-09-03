class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxreach=0;
        int n=nums.size();
        for(int i = 0;i<n;i++){
            if(i>maxreach){
                return false;
            }
            maxreach=max(maxreach,i+nums[i]);
            if(maxreach>=n-1){
                return true;
            }
        }
        return true;
    }
};