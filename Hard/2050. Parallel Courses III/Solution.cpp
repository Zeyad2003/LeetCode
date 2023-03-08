class Solution {
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time) {
        time.insert(time.begin(), 0); // To make it 1-based.
        vector<vector<int> > adj(n + 5); // Adjacency list to store the graph.
        vector<int> inDegree(n + 5, 0); // To store the in-degree of each node.
        vector<int> completionTime(n + 5, 0); // To store the completion time of each node.

        for (auto &i: relations) { // Store the graph.
            adj[i[0]].emplace_back(i[1]);
            inDegree[i[1]]++;
        }


        // Topological sort.
        queue<int> ready;
        for (int i = 1; i <= n; i++)
            if (!inDegree[i]) // Put ready nodes in the queue.
                ready.emplace(i);

        while(!ready.empty()) {
            int curNode = ready.front();
            ready.pop();
            completionTime[curNode] += time[curNode]; // Add the time needed to complete the current node.

            // Explore all neighbors and if they become ready, put them in the queue.
            for(auto & neighbors : adj[curNode]) {
                if(!(--inDegree[neighbors]))
                    ready.emplace(neighbors);

                // Update the completion with the max time of the neighbors.
                completionTime[neighbors] = max(completionTime[neighbors], completionTime[curNode]);
            }
        }

        return *max_element(completionTime.begin(), completionTime.end()); // Return the maximum completion time.
    }
};