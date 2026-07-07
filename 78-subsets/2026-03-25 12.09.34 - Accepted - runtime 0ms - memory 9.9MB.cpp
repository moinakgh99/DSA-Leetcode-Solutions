class Solution {
public:
    vector<vector<int>> ans;

    void mysubsets(int index, vector<int>& nums, vector<int> &temp) {
        ans.push_back(temp);
        for(int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            mysubsets(i+1, nums, temp);
            temp.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        mysubsets(0, nums, temp);
        return ans;
    }
};