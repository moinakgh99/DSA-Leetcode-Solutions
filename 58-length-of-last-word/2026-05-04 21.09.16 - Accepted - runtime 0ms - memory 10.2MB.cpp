class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        vector<string> v;

        while(ss >> word) v.push_back(word);
        
        int n = v.size();
        string l = v[n-1];

        return l.length();
    }
};