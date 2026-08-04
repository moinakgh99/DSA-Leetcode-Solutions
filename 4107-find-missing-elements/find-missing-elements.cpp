class Solution {
public:

    // Approach 1 ..... using freq array ...
    /*
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();

        vector<int> res;
        vector<int> dig(101, 0);

        for(int x : nums) dig[x] = 1;

        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        for(int i = mn; i <= mx; i++) {
            if(dig[i] == 0) res.push_back(i);
        }

        return res;
    }
    */


    // Approach 2 ... using hashset ....
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;

        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        unordered_set<int> s;
        for(int x : nums) s.insert(x);

        for(int i = mn; i <= mx; i++) {
            if(s.find(i) == s.end()) res.push_back(i);
        }

        return res;
    }
};