class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";   // If there is no common prefix, return an empty string ""

        sort(strs.begin(), strs.end());

        string first = strs.front();  // takes first element 
        string last = strs.back();   // takes the last element

        int i = 0;
        while(i < first.length() && i < last.length() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0,i);

    }
};