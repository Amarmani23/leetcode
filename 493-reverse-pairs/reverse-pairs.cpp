class Solution {
public:
    int mergeSort(vector<int>& nums,int start,int end){
        int cnt=0;
        if(start<end){
            int mid=start+(end-start)/2;
            cnt+=mergeSort(nums,start,mid);
            cnt+=mergeSort(nums,mid+1,end);
            cnt+=merge(nums,start,mid,end);
        }
        return cnt;
    }
    int cnt_pair(vector<int>& nums,int start,int mid,int end){
        int cnt=0;
        int j=mid+1;
        for(int i=start;i<=mid;i++){
            while(j<=end && nums[i]>2LL*nums[j]){
                j++;
            }
            cnt=cnt+(j-(mid+1));
        }
        return cnt;
    }
    int merge(vector<int>& nums,int start,int mid,int end){
        int p=cnt_pair(nums,start,mid,end);
        vector<int>temp;
        int i=start;
        int j=mid+1;
        while(i<=mid && j<=end){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=end){
            temp.push_back(nums[j++]);
        }
        for(int i=start;i<=end;i++){
            nums[i]=temp[i-start];
        }
        return p;
    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};