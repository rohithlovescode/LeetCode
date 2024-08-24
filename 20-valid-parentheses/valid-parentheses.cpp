class Solution {
public:
    bool isValid(string s) {
        stack<int> parentheses;
        for(char c: s){
            if(c=='('||c=='{'||c=='['){
                parentheses.push(c);
            }
            else{
                if(parentheses.empty()){
                    return false;
                }
                if((c==')'&&parentheses.top()!='(')||(c==']'&&
                    parentheses.top()!='[')||(c=='}'&&parentheses.top()!='{')){
                    return false;
                }
                parentheses.pop();
            }
        }
        if(parentheses.empty()){
            return true;
        }
        return false;
    }
};