// https://leetcode.com/problems/count-good-triplets-in-an-array/description/?orderBy=most_votes

# Complexity
- Time complexity:O(nlogn)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(n)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code (ordered_set)
```
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

```

# Code (segment_tree)
```
typedef long long ll;
vector<ll>seg;
vector<ll>v;
int n;


void build(ll l, ll r, ll c = 1){
    if(l == r){
        seg[c] = v[l];
        return;
    }
    ll mid = (l+r)/2;
    build(l,mid,2*c);
    build(mid+1,r,2*c+1);
    seg[c] = seg[2*c]+seg[2*c+1];
    return;
}

ll query(ll l,ll r,ll a,ll b,ll c = 1){
    if(l>b || r<a){
        return 0;
    }
    if(l>=a and r<=b){
        return seg[c];
    }
    ll mid = (l+r)/2;
    return query(l,mid,a,b,2*c)+query(mid+1,r,a,b,2*c+1);
}

void update(ll l,ll r, ll ind, ll c=1){
    if(ind<l || r<ind){
        return;
    }
    if(l == r and l == ind){
        seg[c] = 1;
        return;
    }
    ll mid = (l+r)/2;
    update(l,mid,ind,2*c);
    update(mid+1,r,ind,2*c+1);
    seg[c] = seg[2*c]+seg[2*c+1];    
}
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        ll n = nums1.size();
        v.resize(n+1,0);
        ll ans = 0;
        map<ll,ll>mp;
        for(ll i=0;i<n;i++){
            mp[nums2[i]+1] = i+1;
        }
        seg.clear();
        seg.resize(4*n+1,0);
        build(1,n);
        for(int i=1;i<=n;i++){
            ll r = mp[nums1[i-1]+1];
            ll q = query(1,n,1,r);
            ll d = i-q-1;
            ll e = n-r-d;
            ans += e*q;
            update(1,n,r);
        }
        return ans;
    }
};
```

# upvote if it's help you HAPPY CODING :)
