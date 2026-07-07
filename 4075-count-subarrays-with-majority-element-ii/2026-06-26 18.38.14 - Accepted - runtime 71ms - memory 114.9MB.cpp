class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        // First we have to calculate Cummulative sum of each element
        // target element will be denote as +1 whereas non target element will be denoted as -1;

        // ex; for array :  nums = [1,2,2,3], target = 2
        // here array becomes [-1, 1, 1, -1]
        // cummulative sum will be [-1, 0, 1, 0]
        // instead of using array, we will store this in a variable;

        // we will use map which stores cumSum -> count
        unordered_map<int,int> mp;

        long long cumSum = 0;
        mp[0] = 1;

        long long validLeftCumSum = 0;
        long long ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target) {
                // before increasing cum sum we will find valid left cum sum which is less than the current element
                // means cumSum[i - 1] < cumSum[i], we will find all the counts

                validLeftCumSum += mp[cumSum];
                cumSum++;
            } else {
                cumSum--;
                validLeftCumSum -= mp[cumSum];
            }
            
            mp[cumSum]++;
            ans += validLeftCumSum;
        }

        return ans;
    }
};