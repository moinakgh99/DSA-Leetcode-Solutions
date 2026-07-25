class Solution {
public:

    void check(int n, vector<int> & arr) {
        while(n > 0) {
            int digit = n % 10;
           arr.push_back(digit);
           n /= 10;
        }
    }
    
    int maxProduct(int n) {
        vector<int> arr;
        check(n, arr);
        
        int mx = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            for(int j = i + 1; j < arr.size(); j++) {
                mx = max(mx, arr[i] * arr[j]);
            }
        }
        
        return mx;
    }
};