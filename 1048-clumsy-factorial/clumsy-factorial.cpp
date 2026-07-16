class Solution {
public:
    int clumsy(int n) {
        long long ans = 0;
        int sign = 1;

        for(int i = n; i >= 1; i -= 4) {  // 4 - 4 k group lia h !! 
            long long temp = i;
            if(i - 1 > 0) temp *= (i - 1);
            if(i - 2 > 0) temp /= (i - 2);

            ans += (temp * sign);  // minus bhi h beech mai , to plus krne k lia sign change krna padega !!
            if(i - 3 > 0) ans += (i - 3);
            sign = -1;
        }   

        return ans;
    }
};