class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Approach 1 ...
        // int n = nums.size();
        // sort(nums.begin(), nums.end());

        // return (nums[n-1] - 1) * (nums[n - 2] - 1);


        // Approach 2 ...
        // Creating a min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int n : nums) {
            pq.push(n);
            if(pq.size() > 2) {
                pq.pop();
            }
        }

        int a,b;
        a = pq.top();
        pq.pop();

        b = pq.top();

        return (a-1)*(b-1);

    }
};