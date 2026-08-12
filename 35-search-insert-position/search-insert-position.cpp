class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // auto result=lower_bound(nums.begin(),nums.end(),target);
        // int n=distance(nums.begin(),result);
        // return n;

        //M-2  binary serach
        int n=nums.size();
        int left=0;
        
        int right=n-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};