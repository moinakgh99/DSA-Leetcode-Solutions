class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        int j = 0;
        vector<int> res;

        while(j < n) {
            while(!dq.empty() && dq.front() <= (j-k)) dq.pop_front();
            while(!dq.empty() && nums[j] > nums[dq.back()]) dq.pop_back();

            dq.push_back(j);
            
            if(j >= k-1) res.push_back(nums[dq.front()]);

            j++;
        }

        return res;
    }
};