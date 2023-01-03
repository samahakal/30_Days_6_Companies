// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/


// Time complexity:O(n)
// Space complexity:O(1)
    
// Code

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0;
        int a = 0;
        int b = 0;
        int c = 0;

       
        int st = 0;


        while(i<n){
            if(s[i] == 'a') a++;
            if(s[i] == 'b') b++;
            if(s[i] == 'c') c++;
    
            while(a && b && c ){
                ans += n-i;
                if(s[st] == 'a') a--;
                if(s[st] == 'b') b--;
                if(s[st] == 'c') c--;
                st++;
            }
            i++;
        }
        return ans;
    }
};
// upvote if it's help you HAPPY CODING :)
