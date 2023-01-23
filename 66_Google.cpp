// https://leetcode.com/problems/distinct-echo-substrings/description/

typedef long long ll;
ll mod = 1e9+7;

class Solution {
public:

    int distinctEchoSubstrings(string text) {
        int n = text.size();
        vector<ll>hash(n,0);
        vector<ll>pow(n,0);
        set<ll>st;

        int a = 29;

        hash[0] = text[0];
        pow[0] = 1;
        for(int i=1;i<n;i++){
            hash[i] = (hash[i-1]*a + text[i])%mod;
            pow[i] = (pow[i-1]*a)%mod;
        }


        auto getHash = [&](ll i,ll j){
            if(i == 0) return hash[j];

            ll h = hash[j] - hash[i-1]*pow[j-i+1]%mod;
            if(h<0){
                h += mod;
            }
            return h;
        };

        for(int i=0;i<n;i++){
            for(int len = 1;len+len+i<=n;len++){
                ll h1 = getHash(i,i+len-1);
                ll h2 = getHash(i+len,i+len+len-1);
                if(h1 == h2){
                    st.insert(h1);
                }
            }
        }

        return st.size();
    }
};
