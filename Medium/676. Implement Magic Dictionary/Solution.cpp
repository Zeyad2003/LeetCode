class Trie {
private:
    bool isLeaf;
    unordered_map<char, Trie*> children;
public:
    Trie() : isLeaf(false) {};

    void insert(const string& word) { // Normal insert function
        auto * cur = this;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end())
                cur->children[i]= new Trie();
            cur = cur->children[i];
        }
        cur->isLeaf = true;
    }

    bool search(const string& word, int idx = 0, bool f = false) {
        if(idx == (int) word.size()) return isLeaf and f; // When finishing, check we are on a leaf node and changed a character
        if(children.empty()) return false; // If there are no children, return false

        if(children.find(word[idx]) == children.end()) { // Can't find the character -> must change it
            if(f) return false; // We change before -> return false
            for(auto & i : children) { // Else, try to change with any character
                if(i.second->search(word, idx + 1, true)) return true;
            }
        } else { // Can find the character -> can change or not
            if(children[word[idx]]->search(word, idx + 1, f)) return true; // No need to change

            if(f) return false; // Try to change, but we already changed before -> return false
            for(auto & i : children) { // Try to change with any character
                if(i.first != word[idx] and i.second->search(word, idx + 1, true)) return true;
            }
        }
        return false; // Can't find any word
    }

};

class MagicDictionary {
public:
    Trie *trie; // Create a trie object
    MagicDictionary() {
        trie = new Trie(); // Initialize the trie object
    }

    void buildDict(vector<string> dictionary) {
        for(auto & i : dictionary) trie->insert(i); // Insert all the words in the trie
    }

    bool search(string searchWord) {
        return trie->search(searchWord); // Use search function of trie to search the word
    }
};