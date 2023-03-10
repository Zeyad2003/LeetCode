# [382. Linked List Random Node](https://leetcode.com/problems/linked-list-random-node/)

## Solution
- [Not-Efficient - Accepted]: Use a vector to store all the values in the linked list, and then randomly pick one value from the vector.
- [Efficient - Accepted]: Apply Reservoir Sampling to the linked list
  - The idea is to randomly pick one value from the linked list, and the probability of each value is 1/n
  - The probability of the first value is 1/1, the probability of the second value is 1/2, the probability of the third value is 1/3, and so on
  - The probability of the last value is 1/n, and the probability of the previous value is `(n - 1) / n * 1 / (n - 1) = 1 / n`.
  - So the probability of each value is 1/n.

## Complexity
- Time Complexity: `O(n)`, where `n` is the number of nodes in the linked list.

- Space Complexity: 
   - Using vector: `O(n)`, where `n` is the number of nodes in the linked list.
   - Using reservoir sampling: `O(1)`


## Code
- Reservoir Sampling
```
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = (int) nums.size();
        set<int> st;

        // for each element in nums => put the max value it can reach
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2) nums[i] <<= 1; // max value this element can reach
            st.insert(nums[i]);
        }

        int ans = *st.rbegin() - *st.begin(); // get difference between max and min
        
        // if max become odd we can't replace it by any other value less than it
        // st.begin() -> min value && st.rbegin() -> max value
        while (*st.rbegin() % 2 == 0) {
            int x = *st.rbegin(); // get max
            st.erase(x); // remove max
            st.insert(x >> 1); // update max with its half
            ans = min(ans, *st.rbegin() - *st.begin()); // update ans with minimum difference
        }

        return ans;
    }
};
```
- Using vector
```
class Solution {
public:
    vector<int> store; // Used to store the values of the linked list
    Solution(ListNode* head) {
        while(head) { // Traverse the linked list
            store.emplace_back(head->val);
            head = head->next;
        }
    }

    int getRandom() {
        int idx = rand() % (int) store.size(); // Generate a random index
        return store[idx]; // Return the value at that index
    }
};
```