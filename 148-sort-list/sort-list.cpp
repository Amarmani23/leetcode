/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void merge(vector<int>&arr,int start,int mid,int end){
        int i = start;
        int j=mid+1;
        vector<int>temp;
        while(i<=mid && j<=end){
            if(arr[i]<arr[j]){
                temp.push_back(arr[i]);
                i++;
            }else{
                temp.push_back(arr[j]);
                j++;
            }

        }
        while(i<=mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=end){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            arr[i+start]=temp[i];
        }
    }
    void mergeSort(vector<int>&arr,int start,int end){
        if(start<end){
            int mid=start+(end-start)/2;
            mergeSort(arr,start,mid);
            mergeSort(arr,mid+1,end);
            merge(arr,start,mid,end);
        }
    }
    ListNode* sortList(ListNode* head) {
        ListNode* temp=head;
        vector<int>arr;
        while(temp!=nullptr){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        mergeSort(arr,0,arr.size()-1);
        temp=head;
        int i=0;
        while(temp!=nullptr){
            
            temp->val=arr[i];
            temp=temp->next;
            i++;
        }
        return head;
    }
};