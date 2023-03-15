# [1603. Design Parking System](https://leetcode.com/problems/design-parking-system/)

## Solution
- Use a vector to store the number of available parking spaces for each type of car, and when he asks for a space check if it's available and decrease the number of available or not.
## Complexity
- Time Complexity: `O(q)`, where `q` is the number of queries.

- Space Complexity: `O(1)`.
## Code
```cpp
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
```