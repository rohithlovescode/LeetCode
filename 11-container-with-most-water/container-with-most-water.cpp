class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator lp;
        vector<int>::iterator rp;
        lp=height.begin();
        rp=height.end()-1;
        int sol=0,tempArea;
        while(lp<rp){
            if(*lp>=*rp){
                tempArea=((*rp)*(rp-lp));
                sol=max(sol,tempArea);
                rp--;
            }else{
                tempArea=(*lp)*(rp-lp);
                sol=max(sol,tempArea);
                lp++;
            }
        }
        return sol;
    }
};