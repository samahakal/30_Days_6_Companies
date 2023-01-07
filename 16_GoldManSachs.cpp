https://leetcode.com/problems/max-points-on-a-line/description/

# Approach
<!-- Describe your approach to solving the problem. -->
1) Sort the points 
2) Iterate on points and calculate all possible slope with other points and map in hash map 
3) store a maximum frequency 
4) return ans + 1 

# Complexity
- Time complexity:O(n^2)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int ans = 0;
        sort(points.begin(),points.end());
        float n = points.size();

        for(int i=0;i<n;i++){
            float x1 = points[i][0];
            float y1 = points[i][1];

            unordered_map<float,int>curr;

            for(int j=i+1;j<n;j++){
                float x2 = points[j][0];
                float y2 = points[j][1];
                float slope = (y2-y1)/(x2-x1);
                curr[slope]++;
            }
            for(auto it : curr){
                ans = max(ans,it.second);
            }
        }
       
        return ans+1;
    }
};
```
# upvote if it's help you HAPPY CODING :)
