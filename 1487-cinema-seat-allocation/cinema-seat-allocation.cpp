class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for(auto &reservedSeat : reservedSeats) {
            int row = reservedSeat[0], seat = reservedSeat[1];
            mp[row].insert(seat);
        }

        int res = (n - mp.size()) * 2;

        for(auto &[row, bookedSeats] : mp) {

            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };

            bool grpA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool grpB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool grpC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

            if(grpA && grpC) res += 2;
            else if(grpA || grpB || grpC) res += 1;
        }

        return res;
    }
};