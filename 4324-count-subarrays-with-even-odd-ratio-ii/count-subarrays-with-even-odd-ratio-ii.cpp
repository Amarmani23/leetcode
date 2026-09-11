class Solution {
public:
    long long mergeSort(vector<long long>&pref, int start,int end){
        long long cnt=0;
        if(start<end){
            int mid=start + (end-start)/2;
            cnt+=mergeSort(pref,start,mid);
            cnt+=mergeSort(pref,mid+1,end);
            cnt+=merge(pref,start,mid,end);
        }
        return cnt;
    }
    long long merge(vector<long long>&pref, int start,int mid,int end){
        long long cnt=0;
        int i=start;
        int j=mid+1;
        vector<long long>temp((end-start)+1,0);
        int k=0;
        while(i<=mid && j<=end){
            if(pref[i]>=pref[j]){
                cnt+=(mid-i)+1;
                temp[k++]=pref[j++];
            }else{
                temp[k++]=pref[i++];
            }
        }
        while(i<=mid) temp[k++]=pref[i++];
        while(j<=end) temp[k++]=pref[j++];
        for(int i=start;i<=end;i++){
            pref[i]=temp[i-start];
        }
        return cnt;
    }
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<long long>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+(nums[i]%2==0 ? b : -a);
        }
        return mergeSort(pref,0,n);
    }
};