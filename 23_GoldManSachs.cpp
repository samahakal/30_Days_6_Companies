// https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/

# Code (simple recusion)
```
class Solution {
public:
    int mx = 0;
    vector<int>v;
    void solve(vector<int>&aliceArrows,int n,int val,int arrow,vector<int>&arr){
        // base
        if(n == 0 || arrow == 0){
            if(mx<val){
                mx = val;
                v = arr;
                v[0] = arrow;
            }
            return;
        }

        
        if(aliceArrows[n]<arrow){
            arr[n] = aliceArrows[n]+1;
            solve(aliceArrows,n-1,n+val,arrow-1-aliceArrows[n],arr);
        }
        arr[n] = 0;
        solve(aliceArrows,n-1,val,arrow,arr);

    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>arr(12,0);
        solve(aliceArrows,11,0,numArrows,arr);
        return v;
        
    }
};
```


# Code (bitmask)
```

class Solution {
public:
    int max_points = 0, max_mask = 0;

    void dfs(int k,int numArrows,vector<int>&aliceArrows,int points,int mask){
        if(numArrows>=0 and points>max_points){
            max_points = points;
            max_mask = mask;
        }
        if(k>0){
            dfs(k-1,numArrows-aliceArrows[k]-1,aliceArrows,points+k,mask+(1<<k));
            dfs(k-1,numArrows,aliceArrows,points,mask);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>res(12);
        dfs(11,numArrows,aliceArrows,0,0);
        for(int k=11;k>0;k--){
            if(max_mask&(1<<k)){
                res[k] = aliceArrows[k]+1;
                numArrows -= aliceArrows[k]+1;
            }
        }
        res[0] = numArrows;
        return res;
    }

};
```
// # do upvote if you liked the solution HAPPY CODING :)https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/
