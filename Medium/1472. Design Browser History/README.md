# [1472. Design Browser History](https://leetcode.com/problems/design-browser-history/)

## Solution
- Use a deque to store the history and implement the functions as following.
    - **BrowserHistory**: Initialize the browser history with the homepage.
    - **visit**: Remove all the history after the current page and add the new page to the history.
    - **back**: Go back `steps` number, but don't go out of bounds.
    - **forward**: Go forward `steps` number, but don't go out of bounds.

## Complexity
- **Time Complexity**: O(1) for all the functions.
- **Space Complexity**: O(n) for the history.

## Code
```cpp
class BrowserHistory {
public:
    deque<string> store; // Store the history
    int cur; // Current index

    BrowserHistory(string homepage) {
        store = deque<string>(); // Initialize the deque
        store.emplace_back(homepage); // Add the homepage
        cur = 0; // Set the current index to 0
    }

    void visit(string url) {
        while(cur < (int) store.size() - 1) // Remove all the history after the current index
            store.pop_back();
        store.emplace_back(url); // Add the new url
        cur++; // Move one step forward
    }

    string back(int steps) {
        cur = max(0, cur - steps); // Move back the steps or to the beginning
        return store[cur]; // Return the current url
    }

    string forward(int steps) {
        int lastIdx = (int) store.size() - 1; // Get the last index
        cur = min(lastIdx, cur + steps); // Move forward the steps or to the end
        return store[cur]; // Return the current url
    }
};
```