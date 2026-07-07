class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> arr(n+1, 0);

        for(int i = 0; i < n; i++) {
            if(lights[i] > 0) {
                int v = lights[i];
                int maxi = max(0, i- v);
                int mini = min(n-1, i+v);

                arr[maxi]++;
                if(mini + 1 < n) arr[mini + 1]--;
            }
        }

        vector<int> visible(n, 0);

        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += arr[i];
            visible[i] = (cur > 0);
        }

        int res = 0, i = 0;
        while(i < n) {
            if(visible[i]) {
                i++;
                continue;
            }

            int l = 0;
            while(i < n && !visible[i]) {
                l++;
                i++;
            }
            res += (l+2)/3;
        }
        return res;
    }
};