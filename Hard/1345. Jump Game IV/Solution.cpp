class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = (int) arr.size();
        unordered_map<int, vector<int> > mp; // <value, indices>

        for (int i = 0; i < n; ++i)
            mp[arr[i]].emplace_back(i); // for each value, store its indices

        vector<bool> vis(n + 1, false);
        queue<int> q;
        q.emplace(0); // start from index 0

        for (int level = 0; !q.empty(); ++level) {
            int sz = (int) q.size();
            while (sz--) {
                auto curNode = q.front(); // get the current node
                q.pop(); // remove it from the queue
                if (curNode == n - 1) return level; // if we reached the last index, return the level
                vis[curNode] = true; // mark the current node as visited
                if (curNode - 1 >= 0 and !vis[curNode - 1])
                    q.emplace(curNode - 1); // if the left node is valid, add it to the queue
                if (curNode + 1 < n and !vis[curNode + 1])
                    q.emplace(curNode + 1); // if the right node is valid, add it to the queue

                // add all valid indices of the current value to the queue
                for (auto &child: mp[arr[curNode]])
                    if (!vis[child])
                        q.emplace(child);

                // remove all indices to avoid looping over them again
                mp.erase(arr[curNode]); // if you remove this line, you will get TLE
            }
        }
        return n;
    }
};