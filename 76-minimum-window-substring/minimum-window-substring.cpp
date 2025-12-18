class Solution {
public:
    string minWindow(string s, string t) {
        int finalInd = -1;
        int minWinSize = -1;

        map<char,int> tCount;
        map<char,int> sCount;

        for(char ch : t){
            tCount[ch]++;
        }
        int uniqueChars = tCount.size();
        int numMatching = 0;

        int startInd = 0;
        for(int i = 0; i < s.length(); i++){
            char ch = s[i];
            sCount[ch]++;

            if (sCount[ch] == tCount[ch]) { // changed
                numMatching++; // changed
            }

            while(numMatching == uniqueChars){
                if (minWinSize == -1 || i - startInd + 1 < minWinSize) { // added
                    finalInd = startInd; // changed
                    minWinSize = i - startInd + 1; // changed
                }

                char theCh = s[startInd];
                if (sCount[theCh] == tCount[theCh]) { // changed
                    numMatching--; // changed
                }
                sCount[theCh]--;
                startInd++;
            }
        }

        if(finalInd == -1) return "";
        return s.substr(finalInd, minWinSize);
    }
};
