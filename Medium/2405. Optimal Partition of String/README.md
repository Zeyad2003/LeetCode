# [2405. Optimal Partition of String](https://leetcode.com/problems/optimal-partition-of-string/)

## Solution
- Use a frequency array to count the frequency of each character in the current partition.
- If the character is not present in the current partition, increment the frequency of the character.
- If the character is present in the current partition, start a new partition and reset the frequency array.
## Complexity
- Time Complexity: `O(n)`, where `n` is the size of the string.
- Space Complexity: `O(1)`, as the size of the frequency array is constant.
## Code
```cpp
class Solution {
public:
    int partitionString(string s) {
        int freq[26]; // Store the frequency of each character in the current partition
        int cnt = 1; // Store the number of partitions and consider that now you have 1 partition
        memset(freq, 0, sizeof freq); // Initialize the frequency array with 0
        for(auto & i : s) { // Loop through the string
            if(!freq[i - 'a']) { // If the character is not present in the current partition
                freq[i - 'a']++; // Increment the frequency of the character
            } else { // Found before
                cnt++; // Start a new partition
                memset(freq, 0, sizeof freq); // Reset the frequency array
                freq[i - 'a']++; // Increment the frequency of the character
            }
        }
        return cnt; // Return the number of partitions
    }
};
```