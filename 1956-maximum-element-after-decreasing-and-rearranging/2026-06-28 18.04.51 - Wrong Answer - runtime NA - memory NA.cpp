class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        for(int i = 1; i <= n; i++) {
            if(arr[0] == 1 && abs(arr[i-1] - arr[i]) <= 1) return *max_element(arr.begin(), arr.end());
            else arr[i] = arr[i-1] + 1;
        } 
        return *max_element(arr.begin(), arr.end());
    }
};