// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/


class Solution {
private:
    int solve(long n,long n1,long n2){
        long steps = 0;
        while(n1<=n){
            steps += min(n+1,n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k = k - 1;

        while(k>0){
            long steps = solve(n,curr,curr+1);
            if(steps <= k){
                k -= steps;
                curr = curr+1;
            }
            else{
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};
