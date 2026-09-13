class Solution {
public:

    int overlaps(vector<vector<int>>& img1, vector<vector<int>>& img2, int &row, int &col) {
        int n = img1.size();

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int new_i = i + row;
                int new_j = j + col;

                if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n) continue;

                if(img1[i][j] == 1 && img2[new_i][new_j] == 1) count++;
            }
        }

        return count;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int maxi = 0;

        for(int row = -n+1; row < n; row++) {
            for(int col = -n+1; col < n; col++) {
                int count = overlaps(img1, img2, row, col);
                maxi = max(maxi, count);
            }
        }

        return maxi;
    }
};