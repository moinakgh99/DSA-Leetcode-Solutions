
class Solution {
public:
    typedef pair<int, int> P; 
    // {weight, index}

    typedef tuple<long long, int, int> T;
    // {finishTime, weight, index}

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        int n = servers.size();
        int m = tasks.size();

        // Free servers: smallest weight first, then smallest index
        priority_queue<P, vector<P>, greater<P>> freeServers;

        // Busy servers: earliest finish time first
        priority_queue<T, vector<T>, greater<T>> busyServers;

        // Initially saare servers free hain
        for (int i = 0; i < n; i++) {
            freeServers.push({servers[i], i});
        }

        vector<int> result(m);

        long long currentTime = 0;

        for (int i = 0; i < m; i++) {

            // Task ka arrival time miss nahi hona chahiye
            currentTime = max(currentTime, (long long)i);

            // Jo servers ab tak free ho chuke hain, unhe Free mein bhejo
            while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {

                auto [finishTime, wt, idx] = busyServers.top();
                busyServers.pop();

                freeServers.push({wt, idx});
            }

            // Koi server free nahi hai? Time ko aage jump kara do
            if (freeServers.empty()) {

                // Sabse pehle kaunsa server free hoga?
                currentTime = get<0>(busyServers.top());

                // Same time pe free hone wale SAARE servers ko move karo
                while (!busyServers.empty() && get<0>(busyServers.top()) <= currentTime) {

                    auto [finishTime, wt, idx] = busyServers.top();
                    busyServers.pop();

                    freeServers.push({wt, idx});
                }
            }

            // Best available server choose karo
            auto [wt, idx] = freeServers.top();
            freeServers.pop();

            result[i] = idx;

            // Server ab current task process kar raha hai
            busyServers.push({ currentTime + tasks[i], wt, idx });
        }

        return result;
    }
};
