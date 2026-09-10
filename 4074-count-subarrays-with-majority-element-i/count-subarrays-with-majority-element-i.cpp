class Solution {
public:
    int mergeSort(vector<int>&pref,int start,int end){
        int count=0;
        if(start<end){
            int mid=start+(end-start)/2;
            count+=mergeSort(pref,start,mid);
            count+=mergeSort(pref,mid+1,end);
            count+=merge(pref,start,mid,end);
        }
        return count;
    }
    int merge(vector<int>&pref,int start,int mid,int end){
        int count=0;
        vector<int>temp(end-start+1,0);
        int i=start;
        int j=mid+1;
        int k=0;
        while(i<=mid && j<=end){
            if(pref[i]<pref[j]){
                count+=(end-j+1);
                temp[k++]=pref[i++];
            }else{
                temp[k++]=pref[j++];
            }
        }
        while(i<=mid) temp[k++]=pref[i++];
        while(j<=end) temp[k++]=pref[j++];
        for(int i = start;i<=end;i++){
            pref[i]=temp[i-start];
        }
        return count;
    }



    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        for(int i =0;i<n;i++){
            pref[i+1]=pref[i]+(nums[i] == target ? 1 : -1);
        }
        int ans=mergeSort(pref,0,n);
        return ans;
    }
};