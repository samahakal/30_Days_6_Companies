https://leetcode.com/problems/valid-square/description/
# Approach
<!-- Describe your approach to solving the problem. -->
1) caluculate all possible distance
2) if four sides are equal and its diagonal are also equal then return true (size of set is 2 )
3) else return false
# Complexity
- Time complexity:O(1)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int sam = -10;
    int d(vector<int>&a,vector<int>&b){
        if(a[0] == b[0] and a[1] == b[1]){
            return sam++;
        }
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]); 
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int>st{d(p1,p2),d(p1,p3),d(p1,p4),d(p2,p3),d(p2,p4),d(p3,p4)};
        return st.size() == 2;
    }
};
```

# Simple Code
```
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1 == p2 || p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4 || p3 == p4) return false;
       
        int p12 = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
        int p13 = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]);
        int p14 = (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]);
        int p23 = (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]);
        
        int p24 = (p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]);

        int p34 = (p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]);


        if(p12 == p13 and p24 == p34 and p12 == p24 and p14 == p23){
            return true;
        }

        if(p12 == p14 and p23 == p34 and p12 == p23 and p13 == p24){
            return true;
        }

        if(p14 == p13 and p24 == p23 and p14 == p24 and p12 == p34){
            return true;
        }

        return false;
    }
};
```

# upvote if it's help you HAPPY CODING:)
