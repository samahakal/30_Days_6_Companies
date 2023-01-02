
// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

# Complexity
- Time complexity:O(nlogn)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int d;

    long long mergeSort(vector<int>&v,int st,int mid,int en){
        long long cnt = 0;
        int i = st;
        int j = mid + 1;
        while(i<=mid and j<=en){
            if(v[i] <= v[j] + d){
                cnt += (en-j+1);
                i++;
            }
            else{
                j++;
            }
        }
        // we can also sort it in linear time (for TC : O(nlogn))
        sort(v.begin() + st,v.begin() + en + 1);

        return cnt;
    }

    long long merge(vector<int>&v,int st,int en){
        long long cnt = 0;
        if(st<en){
            int mid = st + (en-st)/2;
            cnt += merge(v,st,mid);
            cnt += merge(v,mid+1,en);
            cnt += mergeSort(v,st,mid,en);
        }
        return cnt;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>v;
        d = diff;
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i] - nums2[i]);
        }
        return merge(v,0,v.size()-1);
    }
};
```
