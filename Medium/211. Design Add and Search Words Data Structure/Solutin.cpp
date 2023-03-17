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