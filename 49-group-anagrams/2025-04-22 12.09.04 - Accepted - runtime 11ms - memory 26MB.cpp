class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string,vector<string>>mpp;
     vector<vector<string>>result;
     for(auto x : strs){
        string var = x;
        sort(x.begin() , x.end());
        mpp[x].push_back(var);
     }
     for(auto vect : mpp){
        result.push_back(vect.second);
     }
     return result;

    }
};