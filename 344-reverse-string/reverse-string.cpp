class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<int> stk;
        for(int i=0;i<s.size();i++){
            stk.push(s[i]);
        }
        for(int i=0;i<s.size();i++){
            s[i]=stk.top();
            stk.pop();
        }
    }
};