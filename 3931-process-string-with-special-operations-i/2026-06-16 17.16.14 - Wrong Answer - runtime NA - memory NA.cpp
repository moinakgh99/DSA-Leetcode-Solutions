class Solution {
public:

    string reverse(string s) {
        int n = s.length();
        int i = 0, j = n-1;

        while(i <= j) {
            swap(s[i], s[j]);
            i++; j--;
        }
        return s;
    }

    string processStr(string s) {
        int n = s.length();
        string res = "";
        for(char c : s) {
            if(c == '+') {
                res.pop_back();
            }
            else if(c == '#') {
                res.push_back(res.back());
            }
            else if(c == '%') {
                res = reverse(s);
            }
            else {
                res += c;
            }
        }

        return res;
    }
};