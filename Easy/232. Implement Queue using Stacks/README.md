# [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)

## Solution
- Use 2 stacks, one to push elements, another to pop elements.
## Complexity
- Time Complexity: `O(1)`.

- Space Complexity: `O(n)`, for the `st1` and `st2` stack.
## Code
```cpp
class MyQueue {
public:
    stack<int> st1, st2; // First stack to push elements, second to pop elements
    MyQueue() { // empty constructor
    }

    void prepare() { // Function to prepare the second stack to pop elements, when needed
        if(st2.empty()) {
            while(!st1.empty()) {
                st2.emplace(st1.top());
                st1.pop();
            }
        }
    }

    void push(int x) { // Put the element in the first stack
        st1.emplace(x);
    }

    int pop() { // The front element will be the top of the second stack
        prepare(); // Prepare the second stack
        int x = st2.top(); // Get the top element
        st2.pop(); // Remove the top element
        return x; // Return the top element
    }

    int peek() {
        prepare(); // Prepare the second stack
        return st2.top(); // Return the top element without removing it
    }

    bool empty() { // Check if both stacks are empty
        return st1.empty() and st2.empty();
    }
};
```