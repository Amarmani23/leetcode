class Solution {
public:
    void mergeSort(vector<pair<int,int>>&numPair,vector<int>& ans,int start,int end){
        if(start<end){
            int mid=start+(end-start)/2;
            mergeSort(numPair,ans,start,mid);
            mergeSort(numPair,ans,mid+1,end);
            merge(numPair,ans,start,mid,end);
        }
    }
    void merge(vector<pair<int,int>>&numPair,vector<int>& ans,int start,int mid,int end){
        vector<pair<int,int>>temp(end-start+1);
        int k=0;
    
        int i=start;
        int j=mid+1;
        while(i<=mid && j<=end){
            if(numPair[i].first<=numPair[j].first){
                temp[k++]=numPair[j++];
            }else{
                ans[numPair[i].second] +=end-j+1;
                temp[k++]=numPair[i++];

            }
        }
        while(i<=mid){
            temp[k++]=numPair[i++];
        }
        while(j<=end){
            temp[k++]=numPair[j++];
        }
        for(int i=start;i<=end;i++){
            numPair[i]=temp[i-start];
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>numPair;
        for(int i =0;i<n;i++){
            numPair.push_back({nums[i],i});
        }
        vector<int>ans(n,0);
        mergeSort(numPair,ans,0,n-1);
        return ans;
    }
};