class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int result =nums[0] ;
        int j=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-1==nums[j]){
                result+=nums[i];
                j++;
            }else{
                break;
            }
        }
        unordered_set<int>numset(nums.begin(),nums.end());
        while(numset.count(result)){
            result++;
        }
        return result;
        
    }
};