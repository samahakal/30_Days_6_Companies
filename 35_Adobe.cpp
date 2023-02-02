// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/

class Solution {
public:
    int findIntegers(int n) {
        vector<int>fib(31,0);
        fib[0] = 1;
        fib[1] = 2;
        for(int i=2;i<=30;i++){
            fib[i] = fib[i-1] + fib[i-2];
        }

        int k = 30;
        int pre = 0;
        int ans = 0;
        while(k>=0){
            if(n&(1<<k)){
                ans += fib[k];
                if(pre == 0){
                    pre = 1;
                }
                else{
                    return ans;                    
                }
            }
            else{
                pre = 0;
            }
            k--;
        }
        return ans+1;
    }
};
