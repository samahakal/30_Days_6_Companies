class Solution {
public:
    int magicalString(int n) {
        string s = "122";

        for(int i=2;i<n;i++){
            s.append(s[i]-'0',i&1 ? '2' : '1');
        }
        return count(s.begin(),s.begin()+n,'1');
    }
};
