// https://leetcode.com/problems/count-good-triplets-in-an-array/description/?orderBy=most_votes

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
  
typedef long long ll;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {

        ll n = nums1.size();
        vector<ll>pos(n);
        for(ll i=0;i<n;i++){
            pos[nums2[i]] = i;
        }

        ordered_set s;
        ll ans = 0;

        vector<ll>pref(n),suff(n);

        for(ll i=0;i<n;i++){
            ll curr_pos = pos[nums1[i]];

            pref[i] = s.order_of_key(curr_pos);

            s.insert(pos[nums1[i]]);
        }

        s.clear();

        for(ll i=n-1;i>=0;i--){
            ll curr_pos = pos[nums1[i]];
            suff[i] = s.size() - s.order_of_key(curr_pos);
            s.insert(pos[nums1[i]]);
        }

        for(ll i=1;i<n-1;i++){
            ans += pref[i]*suff[i];
        }
        return ans;       
    }
};
