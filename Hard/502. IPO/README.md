# [502. IPO](https://leetcode.com/problems/ipo/)

## Solution
- You need to sort the projects with less capital first.
- Then for every `k`, you add all projects you can afford to the priority queue.
- Finally, you can get the maximum profit from the top of the priority queue, and add it to the total profit.
## Complexity
- Time complexity: `O(nlog(n))` where n is the number of projects.


- Space complexity: `O(n)`, for the vector of pairs we used to sort the projects.


## Code
``` cpp
class Solution {
public:

    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = (int) profits.size();
        vector<pair<int, int> > v(n); // <capital, profit>
        priority_queue<int> pq;

        for (int i = 0; i < n; ++i)
            v[i] = {capital[i], profits[i]}; // add the projects to the vector

        sort(v.begin(), v.end()); // sort based on the smaller capital

        int pointer = 0; // pointer to the current project
        
        while(k--) { // for every k
            while(pointer < n and v[pointer].first <= w) // take all projects you can afford
                pq.emplace(v[pointer++].second);

            if(pq.empty()) break; // if you can't afford any project, break
            
            w += pq.top(); pq.pop(); // take the best project and add it to the total profit
        }
        return w;
    }
};
```