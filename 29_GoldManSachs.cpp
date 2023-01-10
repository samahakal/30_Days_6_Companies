https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

# Approach
<!-- Describe your approach to solving the problem. -->
```
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

by rearranging the above equation

nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])

Now, we add nums[i] - rev(nums[i]) count in ans and difference in map

```

# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```
class Solution {
public:

    int countNicePairs(vector<int>& nums) {

        unordered_map<int,int>mp;
        int mod = 1e9+7;
        long ans = 0;

        for(int i=0;i<nums.size();i++){
            // reverse nums[i]
            string s = to_string(nums[i]);
            reverse(s.begin(),s.end());
            int _num = stoi(s);

            // difference between them
            int k = nums[i] - _num;
            ans += mp[k];       // is k is not present then mp[k] = 0
            mp[k]++;
        }
        return ans%mod;
    }
};
```

# upvote if it's help you HAPPY CODING :)
