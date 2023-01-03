https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

# Approach
<!-- Describe your approach to solving the problem. -->
1) caluclate gcd of numDivide array
2) sort the nums array 
3) iterate on nums array and check if a%nums[i] == 0 return cnt
4) increment k
5) if loop is break or end it's mean not possible then return -1

# Complexity
- Time complexity:O(nlogn + m + gcd) ,  where gcd = log(max(numDivide)) 
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:
    int gcd(int a,int b){
        if(a<b) return gcd(b,a);
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        
        int a = numsDivide[0];
        for(int i=1;i<numsDivide.size();i++){
            a = gcd(a,numsDivide[i]);
        }

        int k = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > a) break;
            if(a%nums[i] == 0) {
                return k;
            }
            k++;
        }
        return -1;
    }
};
```
