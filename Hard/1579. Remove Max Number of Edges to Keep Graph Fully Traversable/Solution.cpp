struct DSU {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        rank.resize(n, 1);
        size.resize(n, 1);
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY, size[rootY] += size[rootX];
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX, size[rootX] += size[rootY];
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
            size[rootX] += size[rootY];
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        int rootX = find(x);
        return size[rootX];
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int> >& edges) {
        auto *alice = new DSU(n + 1);
        auto *bob = new DSU(n + 1);
        int ans = 0;

        for(auto & i : edges) { // Build edges with type 3 first
            auto [type, u, v] = tie(i[0], i[1], i[2]);
            if(type == 3) {
                if(alice->same(u, v)) ans++;
                else alice->Union(u, v), bob->Union(u, v);
            }
        }

        for(auto & i : edges) {
            auto [type, u, v] = tie(i[0], i[1], i[2]);
            if(type == 1) {
                if(alice->same(u, v)) ans++;
                else alice->Union(u, v);
            } else if(type == 2){
                if(bob->same(u, v)) ans++;
                else bob->Union(u, v);
            }
        }

        int aliceComponentSize = alice->get_size(1);
        int bobComponentSize = bob->get_size(1);
        if(aliceComponentSize != n or bobComponentSize != n) return -1; // Not fully connected
        return ans;
    }
};