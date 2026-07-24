class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int s=0;int e=nums.size()-1;
        vector<int>res(nums.size());
        int k=nums.size()-1;
        while(s<=e){
            int s2=nums[s]*nums[s];
            int e2=nums[e]*nums[e];
            if(e2>s2){
                res[k]=e2;
                
                e--;
            }else{
                res[k]=s2;
                s++;
                
            }
            k--;
        }
        return res;
    }
};