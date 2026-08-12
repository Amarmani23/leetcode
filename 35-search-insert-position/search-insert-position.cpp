class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto result=lower_bound(nums.begin(),nums.end(),target);
        int n=distance(nums.begin(),result);
        return n;
    }
};