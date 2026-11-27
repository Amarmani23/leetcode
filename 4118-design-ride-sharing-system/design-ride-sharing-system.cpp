class RideSharingSystem {
    queue<int>rider;
    queue<int>driver;
    bool activeRider[1001]={false};

public:
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        activeRider[riderId]=true;
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!rider.empty() && !activeRider[rider.front()]){
            rider.pop();
        }
        if(rider.empty() || driver.empty()){
            return {-1,-1};
        }
        int driverId=driver.front();
        int riderId=rider.front();

        driver.pop();
        rider.pop();
        return {driverId,riderId};
    }
    
    void cancelRider(int riderId) {
        activeRider[riderId]=false;
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