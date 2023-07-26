# [1870. Minimum Speed to Arrive on Time](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)

## Solution:
- By Applying `Bianry-Search` Algorithm to minimize the `speed` value, you will got the answer.
- The `can` function will check if this `speed` value could be valid or not.
- The function will iterate on the `dist` array, and calculate the time needed to reach the destination.
- If the time is less than or equal `hour` return `true`, otherwise return `false`.

## Complexity
- Time Complexity: `O(Nlog(N))`, where `N` is the length of `dist`.

- Space Complexity: `O(1)`.

## Code
### C++
```cpp
class Solution {
public:
    const int oo = 1e7 + 5;

    bool can(vector<int> &dist, double hour, int mid) {
        int n = (int) dist.size();
        double ret = 0;

        for(int i = 0; i < n - 1; i++) {
            double val = (double) dist[i] / (double) mid;
            val = ceil(val);
            ret += val;
        }
        ret += (double) dist[n - 1] / (double) mid;

        return ret <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int ans = oo;
        int l = 1, r = oo, mid;

        while(l <= r) {
            mid = (l + r) / 2;
            if(can(dist, hour, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return (ans == oo ? -1 : ans);
    }
};
```

### Java
```java
class Solution {
    final int oo = 10000005;

    boolean can(int[] dist, double hour, int mid) {
        int n = dist.length;
        double ret = 0;

        for(int i = 0; i < n - 1; i++) {
            double val = (double) dist[i] / (double) mid;
            val = Math.ceil(val);
            ret += val;
        }
        ret += (double) dist[n - 1] / (double) mid;

        return ret <= hour;
    }

    public int minSpeedOnTime(int[] dist, double hour) {
        int ans = oo;
        int l = 1, r = oo, mid;

        while(l <= r) {
            mid = (l + r) / 2;
            if(can(dist, hour, mid)) {
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return (ans == oo ? -1 : ans);
    }
}
```

### JavaScript
```javascript
let oo = 1e7 + 5;

let can = (dist, hour, speed) => {
  let ret = 0.0, n = dist.length;
  for(let i = 0; i < n - 1; i++)
    ret += Math.ceil(dist[i] / speed);

  ret += dist[n - 1] / speed;
  return ret <= hour;
}

var minSpeedOnTime = function(dist, hour) {
  let l = 1, r = oo, ans = oo, mid;
  while(l <= r) {
    mid = (l + r) / 2;
    mid = parseInt(mid);
    if(can(dist, hour, mid)) {
      ans = mid;
      r = mid - 1;
    } else l = mid + 1;
  }
  ans = parseInt(ans);
  return ans == oo ? -1 : ans;
};

```

### Python
```python
class Solution(object):

  def can(self, dist, hour, mid):
    ret = 0.0
    for i in range(len(dist) - 1):
      ret += math.ceil(dist[i] / mid)
    ret += dist[-1] / mid
    return ret <= hour

  def minSpeedOnTime(self, dist, hour):
    oo = 10**7 + 5
    l, r, ans = 1, oo, oo
    while l <= r:
      mid = (l + r) // 2
      if self.can(dist, hour, mid):
        ans = mid
        r = mid - 1
      else:
        l = mid + 1
    return ans if ans < oo else -1

```
