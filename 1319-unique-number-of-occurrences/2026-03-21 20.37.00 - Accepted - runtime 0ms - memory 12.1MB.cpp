class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i : arr) {
            mp[i]++;
        }
        vector<int> v;
        for(auto &x : mp) {
            v.push_back(x.second);
        }

        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++) {
            if(v[i] == v[i-1]) return false;
        } 
        return true;
    }
};