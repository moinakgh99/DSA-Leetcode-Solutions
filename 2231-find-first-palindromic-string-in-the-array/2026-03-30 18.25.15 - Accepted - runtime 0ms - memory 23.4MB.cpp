class Solution {
public:

    bool isPal(string &words) {
        int i = 0, j = words.size() - 1;
        while(i < j) {
            if(words[i] != words[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        int j = n - 1;
        for(int i = 0; i < n; i++) {
            if(isPal(words[i])) return words[i];
        }

        return "";
    }
};