var maxScore = function (nums1, nums2, k) {
    let n = nums1.length;
    let v = [];
    for (let i = 0; i < n; i++) {
        v[i] = [nums2[i], nums1[i]];
    }
    v.sort((a, b) => b[0] - a[0]);

    let pq = new MinPriorityQueue();
    let sum = 0;
    let ans = 0;

    for (let i = 0; i < k - 1; i++) {
        pq.enqueue(v[i][1]);
        sum += v[i][1];
    }

    for (let i = k - 1; i < n; i++) {
        sum += v[i][1];
        pq.enqueue(v[i][1]);
        ans = Math.max(ans, sum * v[i][0]);

        if (!pq.isEmpty()) {
            sum -= pq.dequeue().element;
        }
    }

    return ans;
};