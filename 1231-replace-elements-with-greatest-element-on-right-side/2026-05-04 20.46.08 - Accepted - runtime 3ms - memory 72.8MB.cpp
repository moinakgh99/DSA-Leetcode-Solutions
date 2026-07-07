class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {

        // // O(n) Space complexity
        // int n = arr.size();
        // vector<int> right_max(n);

        // if(n == 1) right_max[0] = -1;

        // right_max[n-1] = -1;
        // for(int i = n - 2; i >= 0; i--) {
        //     right_max[i] = max(right_max[i+1], arr[i+1]);
        // }
        // return right_max;


        // O(1) Space complexity
        int n = arr.size();
        int right_max = -1;

        for(int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            arr[i] = right_max;
            right_max = max(curr, right_max);
        }

        return arr;
    }
};