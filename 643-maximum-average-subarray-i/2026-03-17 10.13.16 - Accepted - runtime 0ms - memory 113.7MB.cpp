class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int mxsum=0;
        int sum=0;
        for(int i=0; i<k; i++){
            sum+=nums[i];
            mxsum=sum;
        }
            for(int i=k; i<nums.size(); i++){
                sum+=nums[i];
                sum-=nums[i-k]; 
                mxsum=max(sum,mxsum); 
                
                }
        return (double)mxsum/k;
    }
};