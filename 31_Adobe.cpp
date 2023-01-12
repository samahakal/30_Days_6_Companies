// https://leetcode.com/problems/fraction-to-recurring-decimal/description/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = "";

        if((numerator^denominator)<0) ans += '-';

        long num = abs(numerator);
        long den = abs(denominator);

        long q = num/den;
        long r = num%den;

        ans += to_string(q);
        if(r == 0) return ans;

        ans += '.';
        unordered_map<long,int>mp;

        while(r){
            if(mp.count(r)){
                int pos = mp[r];
                ans.insert(pos,"(");
                ans += ')';
                break;
            }
            else{
                mp[r] = ans.size();
                r = r*10;
                ans += to_string(r/den);
                r = r%den;
            }
        }
        return ans;
    }
};
