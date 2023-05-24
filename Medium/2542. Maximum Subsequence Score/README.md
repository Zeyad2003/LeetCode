# [2542. Maximum Subsequence Score](https://leetcode.com/problems/maximum-subsequence-score/)

## Solution:
- We know that we need to maximize the sum of `nums1`.
- So, we can say that, for every element in `nums2`:
    - if we can hold the maximum `k` elements from `nums1` including the `i-th` element we pick from `nums2`.
        - then, we can maximize the sum of `nums1` by picking the `i-th` element from `nums2`.
- Holding the maximum `k` elements from `nums1` can be easily done by using a `min-heap` with size `k`.
- The `min-heap` will keep the smallest element in the top so for every iteration we can replace this smallest one with the `i-th element we choose.

## Complexity
- Time Complexity: `O(Nlog(N))`, where `N` is the length of `nums1`.

- Space Complexity: `O(N)`, for creating the new vector `v`.

## Code
### C++
```cpp
class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        int n = (int) nums1.size();
        vector<pair<int, int> > v;
        for(int i = 0; i < n; i++) v.emplace_back(nums2[i], nums1[i]);
        sort(v.rbegin(), v.rend());

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0, ans = 0;

        for(int i = 0; i < k - 1; i++) {
            pq.emplace(v[i].second);
            sum += v[i].second;
        }

        for(int i = k - 1; i < n; i++) {
            sum += v[i].second;
            pq.emplace(v[i].second);
            ans = max(ans, sum * v[i].first);

            sum -= pq.top();
            pq.pop();
        }

        return ans;
    }
};
```

### JavaScript
```javascript
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
```

### Python
```python
def compare_max(a, b):
    return b - a

class Solution(object):
    def maxScore(self, nums1, nums2, k):
        n = len(nums1)
        v = []
        for i in range(n):
            v.append((nums2[i], nums1[i]))
        v.sort(reverse = True)

        pq = []
        sum = 0
        ans = 0

        for i in range(k - 1):
            heapq.heappush(pq, v[i][1])
            sum += v[i][1]

        for i in range(k - 1, n):
            sum += v[i][1]
            heapq.heappush(pq, v[i][1])
            ans = max(ans, sum * v[i][0])

            sum -= heapq.heappop(pq)

        return ans
```

### Java
```java
class Solution {
    public long maxScore(int[] nums1, int[] nums2, int k) {
        int n = nums1.length;
        int[][] v = new int[n][2];
        for(int i = 0; i < n; i++) v[i] = new int[] {nums2[i], nums1[i]};
        Arrays.sort(v, (a, b) -> b[0] - a[0]);
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        long sum = 0, ans = 0;

        for(int i = 0; i < k - 1; i++) {
            pq.add(v[i][1]);
            sum += v[i][1];
        }

        for(int i = k - 1; i < n; i++) {
            sum += v[i][1];
            pq.add(v[i][1]);
            ans = Math.max(ans, sum * v[i][0]);

            if(!pq.isEmpty()) sum -= pq.poll();
        }

        return ans;
    }
}
```