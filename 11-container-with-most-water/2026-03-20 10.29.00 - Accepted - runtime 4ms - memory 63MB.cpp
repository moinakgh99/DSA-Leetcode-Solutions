class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int l = 0, r = n  - 1;

        while(l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            int area = h * w;
            maxArea = max(maxArea, area);

            if(height[l] > height[r]) r--;
            else l++;
        }

        return maxArea;
    }
};