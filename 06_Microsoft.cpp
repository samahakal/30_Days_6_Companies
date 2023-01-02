// https://leetcode.com/problems/perfect-rectangle/description/

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
1) corner point never repeats
2) non-corner point repeats even times
3) total area and corner points area should be same

# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string,int>mp;

        int x1_min = INT_MAX;
        int y1_min = INT_MAX;
        int x2_max = INT_MIN;
        int y2_max = INT_MIN;

        long area = 0;

        for(auto rec : rectangles){
            string x1 = to_string(rec[0]) + " " + to_string(rec[1]);
            string x2 = to_string(rec[0]) + " " + to_string(rec[3]);
            string x3 = to_string(rec[2]) + " " + to_string(rec[1]);
            string x4 = to_string(rec[2]) + " " + to_string(rec[3]);

            if(!mp.count(x1)) mp[x1]++;
            else mp.erase(x1);

            if(!mp.count(x2)) mp[x2]++;
            else mp.erase(x2);

            if(!mp.count(x3)) mp[x3]++;
            else mp.erase(x3);

            if(!mp.count(x4)) mp[x4]++;
            else mp.erase(x4);

            x1_min = min(x1_min,rec[0]);
            y1_min = min(y1_min,rec[1]);
            x2_max = max(x2_max,rec[2]);
            y2_max = max(y2_max,rec[3]);

            area += (long)(rec[2]-rec[0])*(rec[3]-rec[1]);
        }

        string x1 = to_string(x1_min) + " " + to_string(y1_min);
        string x2 = to_string(x1_min) + " " + to_string(y2_max);
        string x3 = to_string(x2_max) + " " + to_string(y1_min);
        string x4 = to_string(x2_max) + " " + to_string(y2_max);
        
        if(!mp.count(x1) || !mp.count(x2) || !mp.count(x3) || !mp.count(x4)|| mp.size()!=4) return false;
        return area == (long)(x2_max-x1_min)*(y2_max-y1_min);
    }
};
```
