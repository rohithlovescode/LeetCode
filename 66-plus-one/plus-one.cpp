class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sumLeft=1;
        for(int i=digits.size()-1;i>=0;i--){
            if(digits[i]+sumLeft<=9){
                digits[i]+=sumLeft;
                return digits;
            }else{
                digits[i]=0;
                if(i==0){
                    digits[0]=1;
                    for(int i=1;i<digits.size()-1;i++){
                        digits[i]=0;
                    }
                    digits.push_back(0);
                }
            }
        }
        return digits;
    }
};