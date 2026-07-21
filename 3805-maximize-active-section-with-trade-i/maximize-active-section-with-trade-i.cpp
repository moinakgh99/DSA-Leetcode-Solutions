class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        
        int countOne = 0;
        for(char c : s) {  // sbse pehle total ones count krliye ...
            if(c == '1') countOne++;
        }

        vector<int> countZero;
        int i = 0;
        while(i < n) {
            if(s[i] == '0') {  // no. of contigous blocks of zero count krne k lia ...
                int start = i;
                while(i < n && s[i] == '0') i++; // agar 0 milte jaa rhe, simply i ++ krte rho ..
                countZero.push_back(i - start);
            }
            else i++;
        }

        int maxOnes = 0;
        for(int i = 1; i < countZero.size(); i++) {  // max kitne zeroes ko 1 convert kr skte ...
            maxOnes = max(maxOnes, countZero[i] + countZero[i - 1]);
        }

        return maxOnes + countOne;  // last me jitne zeroes ko 1 me convert kia usko countOne se plus krdo ...
    }
};