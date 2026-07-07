class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        vector<int> first, second;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) first.push_back(i);
            else if(nums[i] == 2) second.push_back(i);
        }

        if(first.empty() || second.empty()) return -1;

        int i = 0, j= 0, res = INT_MAX;
        while(i < first.size() && j < second.size()) {
            res = min(abs(first[i] - second[j]), res);

            if(first[i] < second[j]) i++;
            else j++;
        }

        return res;

    }
};