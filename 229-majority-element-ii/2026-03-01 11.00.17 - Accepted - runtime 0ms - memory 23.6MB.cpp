class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0, count2 = 0;
        int maj1 = 0, maj2 = 0;

        for(int  i = 0; i < n; i++) {
            if(maj1 == nums[i]) count1++;
            else if(maj2 == nums[i]) count2++;
            else if(count1 == 0) {
                maj1 = nums[i];
                count1++;
            }
            else if(count2 == 0) {
                maj2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        vector<int> result;
        int freq1 = 0, freq2 = 0;

        for(int val : nums) {
            if(val == maj1) freq1++;
            else if(val == maj2) freq2++;
        }

        if(freq1 > n/3) {
            result.push_back(maj1);
        }
        if(freq2 > n/3) {
            result.push_back(maj2);
        }

        return result;
    }
};