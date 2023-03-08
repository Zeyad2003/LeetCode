# [2050. Parallel Courses III](https://leetcode.com/problems/parallel-courses-iii/)

## Solution
- Apply Topological Sort and pass the max time between all courses you can take at the same time to the next level.
## Complexity
- Time complexity: `O(n + m)`, where n is the number of node and m is the number of edges.

- Space complexity: `O(n + m)`, where n is the number of node and m is the number of edges.

### Detailed Complexity Explanation
> Initialization: `O(n)`:
Initializing the vectors for adjacency list, in-degree, and completion time takes `O(n)` time.

> Graph construction: 
`O(m)` the loop that stores the graph by adding the edges to the adjacency list and updating the in-degree of the nodes takes `O(m)` time, where m is the number of edges.

> Topological sort: `O(n + m)`:
The topological sort implemented using a queue takes `O(n + m)` time. This is because each node and each edge is visited once. The loop that initializes the queue with ready nodes takes `O(n)` time, and the loop that explores neighbors of the nodes takes `O(m)` time. Therefore, the total time complexity of the topological sort is `O(n + m)`.

> Computing completion time: `O(m)`
The loop that explores neighbors of each node and updates their completion time takes `O(m)` time, where m is the number of edges.

> Finding maximum completion time: `O(n)`
The time complexity of finding the maximum completion time using the max_element function is `O(n)`, where n is the number of nodes.

## Code

```cpp
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
```