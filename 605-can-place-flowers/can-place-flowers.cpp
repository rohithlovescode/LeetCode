class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count =0;
        for(int i=0;i<flowerbed.size();i++){
            if(i!=flowerbed.size()-1&&flowerbed[i+1]==1){
                continue;
            }else if(i!=0&&flowerbed[i-1]==1){
                continue;
            }else if(flowerbed[i]==1){
                continue;
            }
                
            flowerbed[i]=1;
            count++;
        }
        if(count>=n){
            return true;
        }
        return false;
    }
};