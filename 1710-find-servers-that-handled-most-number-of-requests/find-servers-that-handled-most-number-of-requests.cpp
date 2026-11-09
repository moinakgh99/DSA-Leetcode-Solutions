
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        // Free servers: smallest index first
        set<int> freeServers;

        for(int i = 0; i < k; i++) freeServers.insert(i);

        // Busy servers: {finishTime, serverIndex}
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyServers;

        vector<int> cnt(k, 0);

        int n = arrival.size();

        for(int i = 0; i < n; i++) {

            long long currentTime = arrival[i];

            // Jo servers free ho chuke hain, unhe wapas available kar do
            while(!busyServers.empty() && busyServers.top().first <= currentTime) {

                auto [finishTime, server] = busyServers.top();
                busyServers.pop();

                freeServers.insert(server);
            }

            // Sab busy hain? Is task ko simply skip kar do
            if(freeServers.empty()) continue;

            // Current task ki preferred server index
            int preferred = i % k;

            // Preferred index ya uske baad wala smallest available server
            auto it = freeServers.lower_bound(preferred);

            // Koi bada index nahi mila toh circularly first server se start
            if(it == freeServers.end()) it = freeServers.begin();

            int server = *it;

            freeServers.erase(it);

            // Task successfully assign ho gaya
            cnt[server]++;

            // Server ab task complete hone ke baad hi free hoga
            busyServers.push({
                currentTime + load[i], server
            });
        }

        // Maximum tasks handle karne wale servers find karo
        int maxi = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(cnt[i] == maxi) ans.push_back(i);
        }

        return ans;
    }
};
