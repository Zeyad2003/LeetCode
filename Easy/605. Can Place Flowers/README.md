# [605. Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)

## Solution
- Loop through the array and count the valid places and if you found one mark it that you took it.

## Complexity
- **Time Complexity**: `O(n)`, where `n` is the length of the array.
- **Space Complexity**: `O(1)`.

## Code
```cpp
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = (int)flowerbed.size(); // The size of the array
        for(int i = 0; i < sz; i++) {
            if(!flowerbed[i]) { // If no plot
                if((i - 1 >= 0 and flowerbed[i - 1]) or (i + 1 < sz and flowerbed[i + 1])) // can't put
                    continue;
                else flowerbed[i] = 1, n--; // put it
            }
        }
        return n <= 0; // finish all the plots we want to put
    }
};
```