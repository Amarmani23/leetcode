// class RideSharingSystem {
//     queue<int>rider;
//     queue<int>driver;
//     bool activeRider[1001]={false};

// public:
//     RideSharingSystem() {
        
//     }
    
//     void addRider(int riderId) {
//         rider.push(riderId);
//         activeRider[riderId]=true;
//     }
    
//     void addDriver(int driverId) {
//         driver.push(driverId);
//     }
    
//     vector<int> matchDriverWithRider() {
//         while(!rider.empty() && !activeRider[rider.front()]){
//             rider.pop();
//         }
//         if(rider.empty() || driver.empty()){
//             return {-1,-1};
//         }
//         int driverId=driver.front();
//         int riderId=rider.front();

//         driver.pop();
//         rider.pop();
//         return {driverId,riderId};
//     }
    
//     void cancelRider(int riderId) {
//         activeRider[riderId]=false;
//     }
// };


//using set and hashmap with monotonaccally incresing timestamp

class RideSharingSystem {
private:
    int timestamp=0;
    set<pair<int,int>>rider;
    set<pair<int,int>>driver;
    unordered_map<int,int> riderTime;

public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        int t=timestamp++;
        rider.insert({t,riderId});
        riderTime[riderId]=t;
    }
    
    void addDriver(int driverId) {
        driver.insert({timestamp++,driverId});
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty()){
            return {-1,-1};
        }
        auto[rTime,riderId]= *rider.begin();
        auto[dTime,driverId]=*driver.begin();

        rider.erase(rider.begin());
        driver.erase(driver.begin());
        riderTime.erase(riderId);

        return {driverId,riderId};
    }
    
    void cancelRider(int riderId) {
        auto it=riderTime.find(riderId);
        if(it !=riderTime.end()){
            rider.erase({it->second,riderId});
            riderTime.erase(it);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */