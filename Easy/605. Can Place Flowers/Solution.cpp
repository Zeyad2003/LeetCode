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