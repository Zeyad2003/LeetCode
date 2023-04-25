# [2336. Smallest Number in Infinite Set](https://leetcode.com/problems/smallest-number-in-infinite-set/)

## Solution
- Keep a variable `cur` that save the current smallest number.
- When we invoke `addBack()`, we should check if we already pass this number `num < cur`, then we can add it to the set.
- When we invoke `popSmallest()`, we should see if we already have a smallest numbers than `cur`, that's mean the set isn't empty, then return the first number in the set.
- If the set is empty, then we should return `cur` and increase `cur` by 1.
## Complexity
- Time Complexity: `O((M + N)log(N))`, where `N` is the number of `addBack()` calls and `M` is the number of `popSmallest()` calls.
- Space Complexity: `O(N)`, for the `set`.

## Code
### C++
```cpp
class SmallestInfiniteSet {
public:
    set<int> st; 
    int cur;
    SmallestInfiniteSet() {
        cur = 1;
    }
    
    int popSmallest() {
        int val = *st.begin();
        if(!st.empty()) {
            st.erase(st.begin());
            return val;
        }
        cur++;
        return cur - 1;
    }
    
    void addBack(int num) {
        if(num < cur) st.insert(num);
    }
};
```

### Java
```java
import java.util.*;
class SmallestInfiniteSet {
    TreeSet<Integer> set;
    int cur;
    public SmallestInfiniteSet() {
        cur = 1;
        set = new TreeSet<>();
    }

    public int popSmallest() {
        if(!set.isEmpty()) {
            int val = set.first();
            set.remove(val);
            return val;
        }
        cur++;
        return cur - 1;
    }

    public void addBack(int num) {
        if(num < cur) set.add(num);
    }
}
```
