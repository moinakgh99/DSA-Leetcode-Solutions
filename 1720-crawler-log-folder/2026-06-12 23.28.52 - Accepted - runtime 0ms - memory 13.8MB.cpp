class Solution {
public:
    int minOperations(vector<string>& logs) {
        int c = 0;
        for(string log : logs) {
            if(log == "../") {
                if(c > 0) c--;
            }
            else if(log == "./") continue;
            else c++;
        }
        return c;
    }
};