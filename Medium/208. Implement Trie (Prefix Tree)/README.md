# [208. Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)

## Solution
- You should review the Prefix tree data structure tutorial first before you start this problem.
- I will use hash table to use memory more efficiently.

## Complexity
- **Time Complexity**:
    - `insert`: `O(l)`, where `l` is the length of the word.
    - `search`: `O(l)`, where `l` is the length of the word.
    - `startsWith`: `O(l)`, where `l` is the length of the prefix.
- **Space Complexity**: `O(n)`, where `n` is the total number of characters in the input words.

## Code
```cpp
class Trie {
private:
    bool isLeaf;
    unordered_map<char, Trie*> children;
public:
    Trie() : isLeaf(false) {};

    void insert(string word) {
        auto * cur = this;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end())
                cur->children[i]= new Trie();
            cur = cur->children[i];
        }
        cur->isLeaf = true;
    }

    bool search(string word) {
        auto * cur = this;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end())
                return false;
            cur = cur->children[i];
        }
        return cur->isLeaf;
    }

    bool startsWith(string prefix) {
        auto * cur = this;
        for(auto & i : prefix) {
            if(cur->children.find(i) == cur->children.end())
                return false;
            cur = cur->children[i];
        }
        return true;
    }
};
```