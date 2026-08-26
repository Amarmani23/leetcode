class Solution {
public:
    // int maxSubArray(vector<int>& nums) {
    //     int curr=0;
    //     int maxi=INT_MIN;
    //     for(int i =0 ;i<nums.size();i++){
    //         curr+=nums[i];
    //         maxi=max(maxi,curr);
    //         if(curr<0){
    //             curr=0;
    //         }
            
    //     }
    //     return maxi;
    // }

    //standered kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int curr = nums[0];
        int maxi = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            curr = max(nums[i], curr + nums[i]);
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};