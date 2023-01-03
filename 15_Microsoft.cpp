https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

# Approach
<!-- Describe your approach to solving the problem. -->
1) find the first group where a, b and c counts greater than 0
2) while a,b and c count's greater than 0 then ans += n-i and increment st

# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0;
        int a = 0;
        int b = 0;
        int c = 0;

        for(i=0;i<n;i++){
            if(s[i]=='a') a++;
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
            if(a && b && c){
                break;
            }
        }
        int st = 0;


        while(i<n){
            while(a && b && c ){
                ans += n-i;
                if(s[st] == 'a') a--;
                if(s[st] == 'b') b--;
                if(s[st] == 'c') c--;
                st++;
            }
            if(i+1 == n) break;
            if(s[i+1] == 'a') a++;
            if(s[i+1] == 'b') b++;
            if(s[i+1] == 'c') c++;
            i++;
        }
        return ans;
    }
};
```
# HAPPY CODING:)
