class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest=0;
        int curr=0;
        int jump=0;
        for(int i=0;i<nums.size()-1;i++){
            farthest=max(i+nums[i],farthest);
            if(i==curr){
                jump++;
                curr=farthest;
            }
        }
        return jump;
    }
};