class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;

        for(string c : emails) {
            string local = "", domain = "";
            char pos = c.find('@');
            for(int i = 0; i < pos; i++) {
                if(c[i] == '+') break;
                else if(c[i] == '.') continue;
                local += c[i];
            }
            domain = c.substr(pos);
            s.insert(local + domain);
        }

        return s.size();
    }
};