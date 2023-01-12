// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/description/

//  O(n^3)

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<vector<int>>ld = grid, rd = grid;

        int n = grid.size();
        int m = grid[0].size();

        // presum
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int pi = i-1;
                int pj = j-1;
                if(pi >= 0 and pj >= 0){
                    ld[i][j] += ld[pi][pj];
                }
                pj = j+1;
                if(pi >=0 and pj < m){
                    rd[i][j] += rd[pi][pj];
                }
            }
        }

        set<int>st;

        // solution
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){                
                st.insert(grid[i][j]);
                while(st.size()>3){
                    auto it = st.begin();
                    st.erase(it);
                }
                
                for(int k=1;k<max(n,m);k++){
                    int left = j-k;
                    int right = j+k;
                    int mid = i+2*k;

                    if(left<0 || right>=m || mid>=n) break;

                    int sum = rd[i+k][left] - rd[i][j];
                    sum += ld[i+k][right] - ld[i][j];
                    sum += rd[mid][j] - rd[i+k][right];
                    sum += ld[mid][j] - ld[i+k][left];
                    sum += grid[i][j] - grid[mid][j];

                    st.insert(sum);

                    while(st.size()>3){
                        auto it = st.begin();
                        st.erase(it);
                    }
                }
            }
        }
        vector<int>ans;
        for(auto it : st){
            ans.push_back(it);
            if(ans.size() == 3) break;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
