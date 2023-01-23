https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int n = fruits.size();

        unordered_map<int,int>mp;
        int left = -1;
        int right = 0;

        while(right<n){
            mp[fruits[right]]++; 
            if(mp.size()>2){
                int k = right-1;
                while(k>=0 and fruits[k] == fruits[right-1]){
                    k--;
                }
                mp.erase(fruits[k]);
                left = k;
            }

            ans = max(ans,right-left);
            right++;
        }
        return ans;
    }
};
