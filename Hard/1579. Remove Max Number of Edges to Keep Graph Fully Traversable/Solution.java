class DSU {
        int[] parent;
        int[] rank;
        int[] size;

        DSU(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
            rank = new int[n];
            for(int i = 0; i < n; i++) rank[i] = 1;
            size = new int[n];
            for(int i = 0; i < n; i++) size[i] = 1;
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void Union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return;

            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
            else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
                size[rootX] += size[rootY];
            }
        }

        boolean same(int x, int y) {
            return find(x) == find(y);
        }

        int get_size(int x) {
            int rootX = find(x);
            return size[rootX];
        }
}

class Solution {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
        DSU alice = new DSU(n + 1);
        DSU bob = new DSU(n + 1);
        int ans = 0;

        for (int[] edge : edges) { // Build edges with type 3 first
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(type == 3) {
                if(alice.same(u, v)) ans++;
                else{
                    alice.Union(u, v);
                    bob.Union(u, v);
                }
            }
        }

        for(int[] edge : edges) {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];
            if(type == 1) {
                if(alice.same(u, v)) ans++;
                else alice.Union(u, v);
            } else if(type == 2){
                if(bob.same(u, v)) ans++;
                else bob.Union(u, v);
            }
        }

        int aliceComponentSize = alice.get_size(1);
        int bobComponentSize = bob.get_size(1);
        if(aliceComponentSize != n || bobComponentSize != n) return -1; // Not fully connected
        return ans;
    }
}