class Solution {
public:
    int minRotations(string s) {
        int n = s.length();

        int pointer = s[0] - '0';
        int rotations = min( s[0] - '0', 10 - (s[0] - '0'));

        for(int i = 1; i < n; i++) {
            int digit = s[i] - '0';
            rotations += min( abs(digit - pointer), 10 - abs(digit - pointer));

            pointer = digit;
        }

        return rotations;
    }
};