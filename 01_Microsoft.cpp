// link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

// code
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto it : tokens){
            if((it[0]>='0' and it[0]<='9') || it.size()>1){
                st.push(stoi(it));
            }
            else{
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();

                if(it[0] == '+'){
                    st.push(num2+num1);
                }
                else if(it[0] == '-'){
                    st.push(num2-num1);
                }
                else if(it[0] == '/'){
                    st.push(num2/num1);
                }
                else if(it[0] == '*'){
                    st.push(num2*num1);
                }
            }
        }
        
        return st.top();
    }
};
