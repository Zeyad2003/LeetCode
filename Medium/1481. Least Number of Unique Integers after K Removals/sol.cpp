class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        deque<int> freq;

        for(auto & i : arr) mp[i]++;

        for(auto & i : mp) freq.emplace_back(i.second);
        sort(freq.begin(), freq.end());

        for(auto & i : freq) {
            if(k >= i) k -= i, freq.pop_front();
            else break;
        }

        return (int) freq.size();
    }
};