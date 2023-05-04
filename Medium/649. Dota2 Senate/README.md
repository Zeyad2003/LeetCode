# [649. Dota2 Senate](https://leetcode.com/problems/dota2-senate/)

## Solution:
- Use 2 queue one to store the index of `R` and the other to store the index of `D`.
- The best move for every character is to ban the next opponent character in the other queue.
- We will keep doing this until one of them is empty.
- If the `R` queue is empty, then the `D` queue wins, otherwise the `R` queue wins.
## Complexity
- Time Complexity: `O(N)`, where `N` is the length of `senate`.
- Space Complexity: `O(N)`, for the 2 queues.

## Code
### C++
```cpp
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R, D;
        int n = (int) senate.size();

        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R') R.emplace(i);
            else D.emplace(i);
        }
        
        while(!D.empty() and !R.empty()) {
            int r = R.front(), d = D.front();
            R.pop(), D.pop();
            if(r < d) R.emplace(r + n);
            else D.emplace(d + n);
        }
        
        return R.empty() ? "Dire" : "Radiant";
    }
};
```

### Java
```java
class Solution {
    public String predictPartyVictory(String senate) {
        int n = senate.length();
        Queue<Integer> R = new LinkedList<>(), D = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            if(senate.charAt(i) == 'R') R.add(i);
            else D.add(i);
        }
        
        while(!R.isEmpty() && !D.isEmpty()) {
            int r = R.poll(), d = D.poll();
            if(r < d) R.add(r + n);
            else D.add(d + n);
        }
        
        return (R.isEmpty() ? "Dire" : "Radiant");
    }
}
```