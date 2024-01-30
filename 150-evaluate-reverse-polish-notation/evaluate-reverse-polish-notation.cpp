class Solution {
    int operate(int op1,int op2,string operation){
        if(operation=="*"){
            return op2*op1;
        }
        else if(operation=="/"){
            return op2/op1;
        }else if(operation=="+"){
            return op2+op1;
        }
        else{
            return op2-op1;
        }
    }

    stack<int> s;
public:
    int evalRPN(vector<string>& tokens) {
        int size=tokens.size();
        for(int i=0;i<size;i++){
            if(tokens[i]=="*"||tokens[i]=="-"||tokens[i]=="+"||tokens[i]=="/"){
                int op1=s.top();
                s.pop();
                int op2=s.top();
                s.pop();
                s.push(operate(op1,op2,tokens[i]));
            }
            else{
                int val=stoi(tokens[i]);
                s.push(val);
            }
        }
        return s.top();
    }
};