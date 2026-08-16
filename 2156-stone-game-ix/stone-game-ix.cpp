class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int countZero = 0, countOne = 0, countTwo = 0;

        for(int x : stones) {
            if(x % 3 == 0) countZero++;
            else if(x % 3 == 1) countOne++;
            else countTwo++;
        }

        if(countZero % 2 == 0) return countOne >= 1 && countTwo >= 1;  // agar zero even h to
        return abs(countTwo - countOne) > 2;
    }
};