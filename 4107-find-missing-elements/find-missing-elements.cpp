class Solution {
public:

    // Approach 1 ..... 
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
};