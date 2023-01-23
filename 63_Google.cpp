// https://leetcode.com/problems/sort-an-array/description/

class Solution {
public:
    void mergesort(int st,int mid,int en,vector<int>&nums){
        int a = mid-st+1;
        int b = en-mid;
        vector<int>arr1(a,0);
        vector<int>arr2(b,0);

        for(int i=0;i<a;i++){
            arr1[i] = nums[i+st];
        }
        for(int i=0;i<b;i++){
            arr2[i] = nums[i+mid+1];
        }

        int i=0,j=0,k=st;
        while(i<a and j<b){
            if(arr1[i]<arr2[j]){
                nums[k] = arr1[i];
                i++;
                k++;
            }
            else{
                nums[k] = arr2[j];
                k++;
                j++;
            }
        }

        while(i<a){
            nums[k] = arr1[i];
            i++;
            k++;
        }
        while(j<b){
            nums[k] = arr2[j];
            j++;
            k++;
        }
    }
    void merge(int st,int en,vector<int>&nums){
        if(st<en){
            int mid = (st+en)/2;
            merge(st,mid,nums);
            merge(mid+1,en,nums);

            mergesort(st,mid,en,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        merge(0,n-1,nums);
        return nums;
    }
};
