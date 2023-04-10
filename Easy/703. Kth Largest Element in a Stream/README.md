# [703. Kth Largest Element in a Stream](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

## Solution
- Use a min heap to store elements in ascending order.
- Add new elements to the min heap.
- Remove all elements except the kth largest element.
- Return the kth largest element.

## Complexity
- Time Complexity: `O(log(n))`, for `add`, `O(nlog(n))`, for `KthLargest`.
- Space Complexity: `O(k)`, as we keep `k` elements in the min heap.

## Code
```cpp
class KthLargest {
public:
    int k; // kth largest
    priority_queue<int, vector<int>, greater<>> pq; // Min Heap

    KthLargest(int k, vector<int>& nums) {
        for(auto & i : nums) pq.emplace(i); // Add all elements to min heap
        this->k = k; // Store k
    }

    int add(int val) {
        pq.emplace(val); // Add new element to min heap
        while(pq.size() > k) pq.pop(); // Remove all elements except kth largest
        return pq.top(); // Return kth largest
    }
};
```