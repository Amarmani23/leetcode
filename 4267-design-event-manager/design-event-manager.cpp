class EventManager {
private:
    set<pair<int,int>>activeEvents;
    unordered_map<int,int>eventPriority;
public:
    EventManager(vector<vector<int>>& events) {
        for(const auto &e:events){
            int eventId=e[0];
            int priority=e[1];
            activeEvents.insert({-priority,eventId});
            eventPriority[eventId]=priority;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority=eventPriority[eventId];
        activeEvents.erase({-oldPriority,eventId});
        activeEvents.insert({-newPriority,eventId});
        eventPriority[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(activeEvents.empty()){
            return -1;
        }
        auto it=activeEvents.begin();
        int topEventId=it->second;
        activeEvents.erase(it);
        eventPriority.erase(topEventId);
        return topEventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */