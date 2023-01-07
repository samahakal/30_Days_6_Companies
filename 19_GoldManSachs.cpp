https://leetcode.com/problems/number-of-boomerangs/description/

# Approach
<!-- Describe your approach to solving the problem. -->
1) calculate all possible distance from a point
2) add there frequency (fre * fre-1)

``` 

let consider there are some points A,B,C and D
where from B,C and D -> A is at a length of k 
then total possible pairs are :
A -> BC,BD,CD,CB,DB,DC = 6 = 2 * 3 = 2*3c2 = 2*(3*(3-1)/2) = 3*(3-1)
i.e. 2 * 3C2 (nCr  where n is 3  and r is 2 because of pair)
 = n*(n-1)
```

# Complexity
- Time complexity:O(n^2)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size(); 
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            int x = points[i][0];
            int y = points[i][1];
            for(int j=0;j<n;j++){
                if(j == i) continue;
                mp[(points[j][0]-x)*(points[j][0]-x) + (points[j][1]-y)*(points[j][1]-y)]++;
            }
            for(auto it : mp){
                ans += it.second*(it.second-1);
            }
        }
        return ans;
    }
};
```
# pvote if it's help you HAPPY CODING:)
