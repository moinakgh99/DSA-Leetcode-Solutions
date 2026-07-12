class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copyArr = arr;

        sort(copyArr.begin(), copyArr.end());

        unordered_map<int,int> mp;
        int rank = 1;

        for(int x : copyArr) {
            if(mp.find(x) == mp.end()) {
                mp[x] = rank;
                rank++;
            }
        }
    
        
        vector<int> res;
        for(int x : arr) res.push_back(mp[x]);

        return res;

    }
};