class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0;
        int count = 0, countA = 0, countB = 0, countC = 0;

        for(int r = 0; r < s.length(); r++) {
            if(s[r] == 'a') countA++;
            if(s[r] == 'b') countB++;
            if(s[r] == 'c') countC++;

            while(countA > 0 && countB > 0 && countC > 0) {
                count += (s.length() - r);

                if(s[l] == 'a') countA--;
                if(s[l] == 'b') countB--;
                if(s[l] == 'c') countC--;
                l++;
            }
        }
        return count;
    }
};