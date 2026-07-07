class Solution {
    public int maxRotateFunction(int[] nums) {
        int n = nums.length;
        int sum = 0;
        int fx = 0;
        int max = 0;
        for(int i = 0;i<n;i++){
            fx+=(i*nums[i]);
            sum+=nums[i];
        }
        max = fx;
        for(int i=n-1;i>0;i--){
            fx = (fx-(nums[i]*(n-1))) + (sum-nums[i]);
            max = Math.max(max,fx);
        }
        return max;
    }
}