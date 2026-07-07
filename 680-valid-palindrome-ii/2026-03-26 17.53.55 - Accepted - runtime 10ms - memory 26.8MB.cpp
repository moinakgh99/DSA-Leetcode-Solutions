class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }


    bool validPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            if(s[l] == s[r]) {
                l++;
                r--;
            }
            else {
                return isPalindrome(s,l+1,r) || isPalindrome(s,l,r-1);
            }
        }
        return true;
    }
};