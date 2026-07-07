class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int i = 0, j = 0, c = 0;
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        while(i < seats.size()) {
            if(seats[i] == students[j]) continue;
            c += abs(students[j] - seats[i]);
            i++;
            j++;
        }

        return c;
    }
};