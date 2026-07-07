class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
     int n = prices.size();
     vector<int> res;

    for(int i = 0; i < n; i++) {
        int x = prices[i];
        for(int j = i + 1; j < n; j++) {
            if(prices[j] <= prices[i]) {
                x = prices[i] - prices[j];
                break;
            }
        }
        res.push_back(x);
    }
    return res;   
    }
};