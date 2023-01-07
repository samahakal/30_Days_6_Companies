https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        int five = 0;
        for(int i=5;n/i>0;i*=5){
            five += n/i;
        }
        return five;
    }
};
