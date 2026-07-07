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
        // int small_i = nums[0];
        // for(int j = 1; j < n - 1; j++) {
        //     small_i = min(small_i, nums[j]);
        //     for(int k = j + 1; k < n; k++) {
        //         if(small_i < nums[k] && nums[k] < nums[j]) return true;
        //     }
        // }  
        // return false;


        // O(n) using monotonic stack ..
        // here i < j < k    ......   num1(i)    num2(j)     num3(k)
        // we want num1 < num3 < num2 ...

        int num3 = INT_MIN;
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] < num3) return true;

            while(!st.empty() && nums[i] > st.top()) {
                num3 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }
        return false;
    }
};