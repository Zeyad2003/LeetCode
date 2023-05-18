class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        ret = []
        inDegree = [0] * n

        for [u, v] in edges:
            inDegree[v] += 1

        for node in range(0, n):
            if not inDegree[node]:
                ret.append(node)

        return ret