class Solution {
public:
    int mod = 1e9+7;
    int n;
    vector<vector<pair<int,int>>> dp;


    // Approach 1 ....
    bool isValid(int i, int j, vector<string>& board) {
        return (i >= 0 && i < n && j >= 0 && j < n && board[i][j] != 'X');
    }

    // pair<int, int> solve(int i, int j, vector<string>& board) {

    //     if(board[i][j] == 'E') return {0, 1};
    //     if(board[i][j] == 'X') return {0, 0};
    //     if(dp[i][j] != make_pair(-1, -1)) return dp[i][j];

    //     int upScore = 0, upPath = 0;
    //     int leftScore = 0, leftPath = 0;
    //     int diagScore = 0, diagPath = 0;

    //     char ch = board[i][j];

    //     // STEP : 1
    //     if(isValid(i-1, j, board)) {    // up path starting from n-1, n-1
    //         auto[score, path] = solve(i-1, j, board);
    //         upScore = score;
    //         upPath = path;

    //         if(upPath > 0) upScore += (ch != 'S') ? ch - '0' : 0;
    //     }

    //     if(isValid(i, j - 1, board)) {    // left path starting from n-1, n-1
    //         auto[score, path] = solve(i, j - 1, board);
    //         leftScore = score;
    //         leftPath = path;

    //         if(leftPath > 0) leftScore += (ch != 'S') ? ch - '0' : 0;
    //     }

    //     if(isValid(i-1, j - 1, board)) {    // diagonal path starting from n-1, n-1
    //         auto[score, path] = solve(i-1, j - 1, board);
    //         diagScore = score;
    //         diagPath = path;

    //         if(diagPath > 0) diagScore += (ch != 'S') ? ch - '0' : 0;
    //     }


    //     // STEP : 2
    //     // Now we have to find the best path and best scoree from all of them ...
    //     int bestScore, bestPath;

    //     // agar teeno scores equal ho ...
    //     if(upScore == leftScore && leftScore == diagScore) {
    //         bestScore = upScore;  // kisi ek ko best score maanlo
    //         bestPath = upPath + leftPath + diagPath;  // path sbka add hoga
    //     }

    //     // agar leftScore and upScore dono equal h bss ..
    //     else if(upScore == leftScore) {
    //         bestScore = upScore;
    //         bestPath = upPath + leftPath;

    //         if(diagScore > bestScore || diagScore == bestScore && diagPath > bestPath) {
    //             bestScore = diagScore;
    //             bestPath = diagPath;  // jiska best score hoga uska hi path best path maana jaaega ..
    //         }
    //     }

    //     // agar leftScore and DiagScore dono equal h bss ..
    //     else if(leftScore == diagScore) {
    //         bestScore = leftScore;
    //         bestPath = leftPath + diagPath;

    //         if(upScore > bestScore || upScore == bestScore && upPath > bestPath) {
    //             bestScore = upScore;
    //             bestPath = upPath;
    //         }
    //     }
        
    //     // agar koi bhi equal n ho ...
    //     else {
    //         bestScore = upScore, bestPath = upPath;

    //         if(diagScore > bestScore || diagScore == bestScore && diagPath > bestPath) {
    //             bestScore = diagScore;
    //             bestPath = diagPath;
    //         }

    //         if(leftScore > bestScore || leftScore == bestScore && leftPath > bestPath) {
    //             bestScore = leftScore;
    //             bestPath = leftPath;
    //         }
    //     }

    //     return dp[i][j] = {bestScore , bestPath % mod};    
    // }

    // vector<int> pathsWithMaxScore(vector<string>& board) {
    //     n = board.size();

    //     dp.assign(n, vector<pair<int,int>>(n, {-1, -1}));

    //     pair<int,int> res = solve(n-1, n-1, board);

    //     return {res.first, res.second};
    // }



    // Approach 2 : Bottom UP Approach ....
    vector<int> pathsWithMaxScore(vector<string>& board) {

        n = board.size();

        vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>> (n, {0,0}));

        dp[0][0] = {0, 1};  // E ki values h yeh ...

        // uppar se ssaari values fill krte hua aenga , last me ans return krdenga
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'E' || board[i][j] == 'X') continue;

                int upScore = 0, upPath = 0;
                int leftScore = 0, leftPath = 0;
                int diagScore = 0, diagPath = 0;

                char ch = board[i][j];

                // STEP : 1
                if(isValid(i-1, j, board)) {    // up path starting from n-1, n-1
                    auto[score, path] = dp[i-1][j];
                    upScore = score;
                    upPath = path;

                    if(upPath > 0) upScore += (ch != 'S') ? ch - '0' : 0;
                }

                if(isValid(i, j - 1, board)) {    // left path starting from n-1, n-1
                    auto[score, path] = dp[i][j-1];
                    leftScore = score;
                    leftPath = path;

                    if(leftPath > 0) leftScore += (ch != 'S') ? ch - '0' : 0;
                }

                if(isValid(i-1, j - 1, board)) {    // diagonal path starting from n-1, n-1
                    auto[score, path] = dp[i-1][j-1];
                    diagScore = score;
                    diagPath = path;

                    if(diagPath > 0) diagScore += (ch != 'S') ? ch - '0' : 0;
                }


                // STEP : 2
                // Now we have to find the best path and best scoree from all of them ...
                int bestScore, bestPath;

                // agar teeno scores equal ho ...
                if(upScore == leftScore && leftScore == diagScore) {
                    bestScore = upScore;  // kisi ek ko best score maanlo
                    bestPath = upPath + leftPath + diagPath;  // path sbka add hoga
                }

                // agar leftScore and upScore dono equal h bss ..
                else if(upScore == leftScore) {
                    bestScore = upScore;
                    bestPath = upPath + leftPath;

                    if(diagScore > bestScore || diagScore == bestScore && diagPath > bestPath) {
                        bestScore = diagScore;
                        bestPath = diagPath;  // jiska best score hoga uska hi path best path maana jaaega ..
                    }
                }

                // agar leftScore and DiagScore dono equal h bss ..
                else if(leftScore == diagScore) {
                    bestScore = leftScore;
                    bestPath = leftPath + diagPath;

                    if(upScore > bestScore || upScore == bestScore && upPath > bestPath) {
                        bestScore = upScore;
                        bestPath = upPath;
                    }
                }
                
                // agar koi bhi equal n ho ...
                else {
                    bestScore = upScore, bestPath = upPath;

                    if(diagScore > bestScore || diagScore == bestScore && diagPath > bestPath) {
                        bestScore = diagScore;
                        bestPath = diagPath;
                    }

                    if(leftScore > bestScore || leftScore == bestScore && leftPath > bestPath) {
                        bestScore = leftScore;
                        bestPath = leftPath;
                    }
                }

                dp[i][j] = {bestScore , bestPath % mod};
            }
        }

        auto res = dp[n-1][n-1];
        return {res.first, res.second};
    }    
};