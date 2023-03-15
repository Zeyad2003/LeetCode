class ParkingSystem {
public:
    vector<int> v = {0, 0, 0, 0};
    ParkingSystem(int big, int medium, int small) {
        v[1] = big;
        v[2] = medium;
        v[3] = small;
    }

    bool addCar(int carType) {
        if(v[carType]) {
            v[carType]--;
            return true;
        }
        return false;
    }
};