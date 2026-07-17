class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        
        // Approach 1 : O(n) time and space
        // unordered_map<int,int> mp;
        // for(int x : nums) mp[x]++;
        // for(auto &it : mp) {
        //     if(it.second == 1) return it.first;
        // }
        // return -1;


        // Approach 2 : The question asked ...
        int n = nums.size();
        int start = 0, end = n - 1;

        if(n == 1) return nums[0];

        while(start <= end) {
            int mid = start + (end - start) / 2;

            if(mid == 0 && nums[0] != nums[1]) return nums[mid];
            if(mid == n-1 && nums[mid] != nums[mid - 1]) return nums[mid];
            
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) return nums[mid];

            if(mid % 2 == 0) {  // agar mid even ho ...
                if(nums[mid] == nums[mid - 1]) end = mid - 1;
                else start = mid + 1;
            }
            else {
                if(nums[mid] == nums[mid - 1]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return -1;
    }
};