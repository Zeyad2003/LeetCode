ans = True

def dfs(graph, kind, vis, node):
    global ans
    vis[node] = True

    for child in graph[node]:
        if not vis[child]:
            kind[child] = 1 - kind[node]
            dfs(graph, kind, vis, child)
        elif kind[child] == kind[node]:
            ans = False

class Solution(object):
    def isBipartite(self, graph):
        global ans
        n = len(graph)
        kind = [0] * n
        vis = [False] * n
        ans = True

        for i in range(n):
            if not vis[i]:
                dfs(graph, kind, vis, i)

        return ans