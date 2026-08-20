class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        for(int i = 2; i < n; i++) {
            int a = arr1.size();
            int b = arr2.size();

            if(arr1[a-1] > arr2[b-1]) arr1.push_back(nums[i]);
            else arr2.push_back(nums[i]);
        }

        vector<int> res;
        int i = 0, j = 0;

        while(i < arr1.size()) { res.push_back(arr1[i]); i++; }
        while(j < arr2.size()) { res.push_back(arr2[j]); j++; }
        
        return res;
    }
};