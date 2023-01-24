// https://leetcode.com/problems/strictly-palindromic-number/description/

class Solution {
public:
    bool isPal(string &s){
        int i=0;;
        int j=s.size()-1;
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        int temp;
        string base;

        for(int i=2;i<=n-2;i++){
            temp = n;
            while(temp){
                base = base + to_string(temp%i);
                temp = temp/i;
            }

            if(!isPal(base)) return false;
            base.clear();
        }
        return true;
    }
};
