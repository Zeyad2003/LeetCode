# [1481. Least Number of Unique Integers after K Removals](https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals)

## Solution:
- The target is to minimize the number of unique integers as much as possible, so we need to make the using of `k` is as efficient as possible.
- Using `k` efficiently is equivalent to removing the integers with the smallest frequency.
- We can use a `HashMap` to store the frequency of each integer, then start removing the smallest frequency integers until `k` is used up.
- The remaining integers are the smallest number of unique integers after `k` removals.

## Complexity
- Time Complexity: `O(nlog(n))`, where `n` is the length of `arr`.

- Space Complexity: `O(n)`.

## Code
### C++
```cpp
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        deque<int> freq;

        for(auto & i : arr) mp[i]++;

        for(auto & i : mp) freq.emplace_back(i.second);
        sort(freq.begin(), freq.end());

        for(auto & i : freq) {
            if(k >= i) k -= i, freq.pop_front();
            else break;
        }

        return (int) freq.size();
    }
};
```

### Java
```java
class Solution {
    public int findLeastNumOfUniqueInts(int[] arr, int k) {
        Map<Integer, Integer> mp = new HashMap<>();
        PriorityQueue<Integer> freq = new PriorityQueue<>();

        for(int i : arr) {
            mp.put(i, mp.getOrDefault(i, 0) + 1);
        }

        for(int i : mp.values()) freq.add(i);

        while(!freq.isEmpty()) {
            int i = freq.peek();
            if(k >= i) {
                k -= i;
                freq.poll();
            } else break;
        }

        return freq.size();
    }
}
```

### JavaScript
```javascript
var findLeastNumOfUniqueInts = function(arr, k) {
    let mp = new Map();
    let freq = new MinPriorityQueue();

    for(let i of arr) {
        mp.set(i, mp.get(i) + 1 || 1);
    }

    for(let [key, value] of mp) {
        freq.enqueue(value);
    }

    while(!freq.isEmpty()) {
        let i = freq.front().element;
        if(k >= i) {
            k -= i;
            freq.dequeue();
        } else break;
    }

    return freq.size();
};
```

### Python
```python
class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        mp = {}
        freq = []

        for i in arr:
            if i in mp: mp[i] += 1
            else: mp[i] = 1

        for i in mp: freq.append(mp[i])

        freq.sort()

        while freq:
            i = freq[0]
            if k >= i:
                k -= i
                freq.pop(0)
            else:
                break

        return len(freq)
       
```
