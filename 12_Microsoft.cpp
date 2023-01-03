// https://leetcode.com/problems/longest-happy-prefix/description/


class Solution {
public:
    int KMP(string s){
        int n = s.size();
        vector<int>lp(n,0);
        int index = 0;
        for(int i=1;i<n;){
            if(s[i] == s[index]){
                lp[i] = index + 1;
                i++;
                index++;
            }
            else{
                if(index == 0){
                    i++;
                }
                else{
                    index = lp[index-1];
                }
            }
        }
        return lp[n-1];
    }
    string longestPrefix(string s) {
        int k = KMP(s);
        return s.substr(0,k);
    }
};
