class Solution {
public:

    bool balance( unordered_map<int,int> &freq) {
        if(freq.size() == 1) return true;

        int freqMaxi = 0;
        for(auto &it : freq) {
            freqMaxi = max(freqMaxi, it.second); 
        }

        if(freqMaxi % 2 != 0) return false;

        int reqFreq = freqMaxi / 2;
        bool found = false;

        for(auto &it : freq) {
            int currFreq = it.second;
            if(currFreq == freqMaxi) continue;
            if(currFreq == reqFreq){
                found = true;  
            }
            else {
                return false;
            }
        }

        return found;
    }
    
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int res = -1;

        for(int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            for(int j = i; j < n; j++) {
                freq[nums[j]]++;
                if(balance(freq)) {
                    res = max(res, j - i + 1);
                }
            }
        }

        return res;
    }
};