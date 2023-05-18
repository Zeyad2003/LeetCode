var findSmallestSetOfVertices = function(n, edges) {
    let inDegree = new Array(n).fill(0);
    let ret = [];

    for(let [u, v] of edges)
        inDegree[v]++;

    for(let node = 0; node < n; node++)
        if(!inDegree[node])
            ret.push(node);

    return ret;
};