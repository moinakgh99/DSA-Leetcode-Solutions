class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums) {
            freq[x]++;
        }

        int maxElem = *max_element(nums.begin(), nums.end());
        int minElem = *min_element(nums.begin(), nums.end());

        vector<int> result;
        for(int i = minElem; i <= maxElem; i++) {
            while(freq[i] > 0) {
                result.push_back(i);
                freq[i]--;
            }
        }
        return result;
    }
};