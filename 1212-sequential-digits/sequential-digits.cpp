class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        

        // Approach 1 : Using BFS ....
        // queue<int> q;
        // for(int i = 1; i <= 8; i++) {
        //     q.push(i);
        // }

        // vector<int> res;
        // while(!q.empty()) {
        //     int num = q.front();
        //     q.pop();

        //     if(num >= low && num <= high) res.push_back(num);

        //     int dig = num % 10;
        //     if((dig + 1) <= 9) q.push(num * 10 + (dig + 1));
        // }

        // return res;


        // Approach 2 : Simply store all the result in a vector .
        vector<int> allPossible = {12, 23, 34, 45, 56, 67, 78, 89,
                          123, 234, 345, 456, 567, 678, 789,
                          1234, 2345, 3456, 4567, 5678, 6789,
                          12345, 23456, 34567, 45678, 56789,
                          123456, 234567, 345678, 456789,
                          1234567, 2345678, 3456789,
                          12345678, 23456789,
                          123456789
        };

        vector<int> res;

        for(int i = 0; i < allPossible.size(); i++) {
            if(allPossible[i] < low) continue;
            if(allPossible[i] > high) break;

            res.push_back(allPossible[i]);
        }

        return res;
    }
};