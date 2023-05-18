class Solution {
    public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
        List<Integer> ret = new ArrayList<>();
        int[] inDegree = new int[n];

        for (List<Integer> edge : edges)
            inDegree[edge.get(1)]++;

        for(int node = 0; node < n; node++)
            if(inDegree[node] == 0) ret.add(node);

        return ret;
    }
}