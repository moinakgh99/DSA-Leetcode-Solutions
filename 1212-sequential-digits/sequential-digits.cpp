class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        

        // Approach 1 : Using BFS ....
        queue<int> q;
        for(int i = 1; i <= 8; i++) {
            q.push(i);
        }

        vector<int> res;
        while(!q.empty()) {
            int num = q.front();
            q.pop();

            if(num >= low && num <= high) res.push_back(num);

            int dig = num % 10;
            if((dig + 1) <= 9) q.push(num * 10 + (dig + 1));
        }

        return res;
    }
};