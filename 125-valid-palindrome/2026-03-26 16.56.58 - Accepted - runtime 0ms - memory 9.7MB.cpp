class Solution {
public:
    bool isAlphaNum(char ch) {
        if(ch >= '0' && ch <= '9'|| tolower(ch) >= 'a' && tolower(ch) <= 'z')            {return true;}
        return false;
    }


    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(!isAlphaNum(s[l])) {
                l++;
                continue;
            }
            if(!isAlphaNum(s[r])) {
                r--;
                continue;
            }
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
        }

        return true;
    }
};