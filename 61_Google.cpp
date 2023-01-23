// https://leetcode.com/problems/maximum-consecutive-floors-without-special-floors/description/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int ans = 0;
        int n = special.size();
        for(int i=1;i<n;i++){
            ans = max(ans,special[i]-special[i-1]-1);
        }


        int k = lower_bound(special.begin(),special.end(),bottom)-special.begin();
        if(k<n and special[k]<=top){
            ans = max(ans,special[k]-bottom);
        }
        k = upper_bound(special.begin(),special.end(),top)-special.begin()-1;
        if(k>=0 and special[k]>=bottom){
            ans = max(ans,top-special[k]);
        }

        return ans;
    }
};
