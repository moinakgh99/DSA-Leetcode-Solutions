class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> need;

        for(int i = 0; i < capacity.size(); i++) {
            need.push_back(capacity[i] - rocks[i]);
        }

        sort(need.begin(), need.end());

        int count = 0;
        for(int i = 0; i < need.size(); i++) {
            if(need[i] == 0) count++;
            else if(additionalRocks >= need[i]) {
                additionalRocks -= need[i];
                count++;
            }
            else break;
        }
        return count;
    }
};