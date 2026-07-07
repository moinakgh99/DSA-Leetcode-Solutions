class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();


        // Solution is O(N3) , SO THERE WILL BE tle ...     
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] < nums[j]) {  // Jaao tabhi jb nums[i] , nums[j] se chota ho ..
        //             for(int k = j + 1; k < n; k++) {
        //                 if(nums[i] < nums[k] && nums[k] < nums[j]) return true;
        //             }
        //         }
        //     }
        // }
        // return false;


        // O(n2) solution ..
        int small_i = min_element(nums.begin(), nums.end()) - nums.begin();
        for(int j = small_i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(small_i < nums[k] && nums[k] < nums[j]) return true;
            }
        }
        return false;   
    }
};