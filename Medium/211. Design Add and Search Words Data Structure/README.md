# [211. Design Add and Search Words Data Structure](https://leetcode.com/problems/design-add-and-search-words-data-structure/)

## Solution
- You should review the Prefix tree data structure `(Trie)` tutorial first before you start this problem.
- I will use hash table to use memory more efficiently.

## Complexity
- **Time Complexity**:
    - `insert`: `O(l)`, where `l` is the length of the word.
    - `search`: `O(k * 26^m)`, where `k` is the number of words in the trie, `m` is the maximum length of any word in the trie, and `26` is the number of possible characters in the English alphabet.
- **Space Complexity**: `O(n)`, where `n` is the total number of characters in the input words.

## Code
```cpp
class WordDictionary {
public:
    bool isLeaf;
    unordered_map<char, WordDictionary *> child;

    WordDictionary() : isLeaf(false) {}

    void addWord(string word) { // Insert in the Trie normally
        auto *cur = this;
        for (const auto &i: word) {
            if (cur->child.find(i) == cur->child.end())
                cur->child[i] = new WordDictionary();
            cur = cur->child[i];
        }
        cur->isLeaf = true;
    }

    bool search(string word) {
        return searchHelper(this, word, 0); // Use this helper function to search
    }

    bool searchHelper(WordDictionary *root, string &word, int idx) {
        if(idx == (int) word.size()) // If we have reached the end of the word
            return root->isLeaf; // Check if the last node is a leaf node

        if(word[idx] == '.') { // If the current character is a wildcard
            auto ans = false;
            for(auto it : root->child) { // Try all the possible characters
                ans |= searchHelper(it.second, word, idx + 1); // If any of them return true -> return true
            }
            return ans; // Return true if any of the paths return true
        }

        else {
            if(root->child.find(word[idx]) == root->child.end()) return false; // No child with current node -> return false
            return searchHelper(root->child[word[idx]], word, idx + 1); // Search in the child with the current character
        }

        return false;
    }
};
```