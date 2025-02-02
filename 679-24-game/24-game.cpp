class Solution {
public:
    vector<char> ops={'+','-','*','/'};
    float oper(float a,float b, char op){
        if(op=='+'){
            return a+b;
        }else if(op=='-'){
            return a-b;
        }else if(op=='*'){
            return a*b;
        }else if(b!=0){
            return a/b;
        }
        return -0.001;
    }
    bool checkOrder(vector<int>& arr){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                for(int k=0;k<8;k++){
                    char op_i=ops[i%4];
                    char op_j=ops[j%4];
                    char op_k=ops[k%4];
                    float temp;
                    if(i<4){
                        if(j<4){
                            temp=oper(oper(oper(arr[0],arr[1],op_i),arr[2],op_j),arr[3],op_k);
                        }else{
                            temp=oper(oper(arr[0],arr[1],op_i),oper(arr[2],arr[3],op_k),op_j);
                        }
                    }else if(j<4){
                        if(k<4){
                            temp=oper(oper(arr[0],oper(arr[1],arr[2],op_j),op_i),arr[3],op_k);
                        }else{
                            temp=oper(arr[0],oper(oper(arr[1],arr[2],op_j),arr[3],op_k),op_i);
                        }
                    }else{
                        temp=oper(arr[0],oper(arr[1],oper(arr[2],arr[3],op_k),op_j),op_i);
                    }
                    if(temp>=23.98&&temp<=24.02){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void getAllPermutations(vector<int>& arr, int start, vector<vector<int>>& result) {
        if (start == arr.size()) {
            result.push_back(arr);
            return;
        }
        for (int i = start; i < arr.size(); i++) {
            swap(arr[start], arr[i]);
            getAllPermutations(arr, start + 1, result);
            swap(arr[start], arr[i]);
        }
    }

    bool judgePoint24(vector<int>& cards) {
        vector<vector<int>> allPermutations;
        getAllPermutations(cards,0,allPermutations);
        for(auto card:allPermutations){
            if(checkOrder(card)){
                return true;
            }
        }
        return false;
    }
};