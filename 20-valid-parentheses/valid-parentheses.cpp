class Solution {
public:
    bool checkParanthesis(char ch1,char ch2){
        return ch1=='('&&ch2==')'||ch1=='{'&&ch2=='}'||ch1=='['&&ch2==']';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto& ch: s){
            if(ch=='('||ch=='{'||ch=='['){
                st.push(ch);
            }
            else{
                if(st.empty()){
                    return false;
                }
                if(checkParanthesis(st.top(),ch)){
                    st.pop();
                }else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};