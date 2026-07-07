class EventManager {
public:
    unordered_map<int,int> mp;
    priority_queue<pair<int,int>> pq;
    
    EventManager(vector<vector<int>>& events) {
        auto denqoravil = events;
        for(auto &e : events) {
            mp[e[0]] = e[1];
            pq.push({e[1], -e[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        while(!pq.empty()) {
            auto[p, negId] = pq.top();
            pq.pop();

                int id = -negId;
            
            if(mp.count(id) && mp[id] == p) {
                mp.erase(id);
                return id;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */