# [496. Next Greater Element I](https://leetcode.com/problems/next-greater-element-i/)

## Solution
- Use a stack to find the next greater element for each element in nums2
- Use a hashTable to store the next greater element for each element in nums2
- Iterate through nums1 and find the next greater element for each element in nums1
## Complexity
- Time complexity: `O(n)`, where n is the length of `nums2`.

- Space complexity: `O(n)`, the size of the stack and the hashTable.

## Code

```cpp
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st; // To find the next element for each element in nums2
        unordered_map<int, int> mp; // mp[x] = next greater element of x

        for(int i = (int)nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() and st.top() <= nums2[i]) // Keep popping until you find a greater element or the stack is empty
                st.pop();

            if(st.empty())
                mp[nums2[i]] = -1; // No greater element found
            else
                mp[nums2[i]] = st.top(); // The next greater element is the top of the stack

            st.push(nums2[i]);
        }

        for(auto & i : nums1) i = mp[i]; // Update nums1 with the next greater elements

        return nums1;
    }
};
```