class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> one, two;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) one.push_back(i);
            else if(nums[i] == 2) two.push_back(i);
        }

        if(one.empty() || two.empty()) return -1;

        int i = 0, j = 0, ans = INT_MAX;

        while(i < one.size() && j < two.size()) {
            ans = min(ans, abs(one[i] - two[j]));

            if(one[i] < two[j]) i++;
            else j++;
        }

        return ans;
    }
};