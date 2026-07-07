class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> right_max(n);

        if(n == 1) right_max[0] = -1;

        right_max[n-1] = -1;
        for(int i = n - 2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], arr[i+1]);
        }
        return right_max;
    }
};