class ParkingSystem {
public:
    int cap[4];
    ParkingSystem(int big, int medium, int small) {
        cap[1] = big;
        cap[2] = medium;
        cap[3] = small;
    }
    
    bool addCar(int carType) {
        if(cap[carType] == 0) return false;

        cap[carType]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */