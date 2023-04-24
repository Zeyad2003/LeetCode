# [1046. Last Stone Weight](https://leetcode.com/problems/last-stone-weight/)

## Solution
- Use a `priority_queue` to store the stones.
- While there's more than 1 stones, pop the two largest stones take them and apply the conditions normally.
- If there's only one stone left, return it, otherwise return 0.
## Complexity
- Time Complexity: `O(Nlog(N))`, where `N` is the length of the array `stones`.
- Space Complexity: `O(N)`, for the `priority_queue`.

## Code
### C++
```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(auto & i : stones) q.emplace(i);
        
        while((int) q.size() > 1) {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(x == y) continue;
            else q.emplace(y - x);
        }
        
        if(!q.empty()) return q.top();
        else return 0;
    }
};
```

### Java
```java
import java.util.*;
class Solution {
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        for (int i : stones) q.add(i);

        while (q.size() > 1) {
            int y = q.peek();
            q.poll();
            int x = q.peek();
            q.poll();
            if (x != y) q.add(y - x);
        }

        if (q.size() > 0) return q.peek();
        else return 0;
    }
}
```
