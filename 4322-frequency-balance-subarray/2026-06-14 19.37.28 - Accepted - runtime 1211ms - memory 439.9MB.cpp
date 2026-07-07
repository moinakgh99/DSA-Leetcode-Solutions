class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i =0; i<n; i++){
            unordered_map<int, int> mpp;
            int maxFreq = 0;
            for(int j =i; j<n; j++){
                bool flag = false;
                mpp[nums[j]]++;
                maxFreq = max(maxFreq, mpp[nums[j]]);
                if(maxFreq % 2 != 0){
                    continue;
                }
                if(mpp.size() == 1){
                    ans = max(ans, mpp[nums[j]]);
                }
                else{
                    for(auto it : mpp){
                        if(it.second == maxFreq){
                            continue;
                        }
                        else if(it.second == maxFreq/2){
                            flag = true;
                        }
                        else if(it.second < maxFreq && it.second != maxFreq/2){
                            flag = false;
                            break;
                        }
                    }
                }
                if(flag){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};