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