class Trie {
private:
    int idx; // Index of the word
    unordered_map<char, Trie*> children; // Children of the trie
public:
    Trie() : idx(-1) {}; // Initialize the index to -1

    void insert(const string& word, int wordIdx) {
        auto * cur = this;
        for(auto & i : word) { // Normal trie insert
            if(cur->children.find(i) == cur->children.end())
                cur->children[i]= new Trie();
            cur = cur->children[i];
        }
        cur->idx = max(cur->idx, wordIdx); // Update the index of the word with the max index -> handle duplicate words
    }

    int search(const string& word) {
        auto * cur = this;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end())
                return -1; // We can't find the word with the same suffix and prefix -> return -1
            cur = cur->children[i];
        }
        int ans = -1; // Initialize the answer to -1
        searchHelper(cur, ans); // Traverse all the words that have the same suffix and prefix and update the max index
        return ans; // Return the max index
    }

    void searchHelper(Trie* root, int &ans) {
        if(~root->idx) ans = max(ans, root->idx); // Found a word -> maximize the index
        for(auto & i : root->children) searchHelper(i.second, ans); // Traverse all the children
    }
};

class WordFilter {
public:
    Trie *trie; // Trie to store all words in the form of suffix + "." + prefix

    WordFilter(vector<string>& words) {
        trie = new Trie(); // Initialize an empty trie

        for(int i = 0; i < (int) words.size(); i++) {
            string tmp = words[i], dot = "."; // dot is used to separate prefix and suffix
            while(!words[i].empty()) { // While there's still a suffix
                // Insert the suffix of the word in the trie + dot + the word itself and its index
                trie->insert(words[i] + dot + tmp, i);
                words[i].erase(words[i].begin()); // Remove the first character of the suffix
            }
        }
    }

    int f(string pref, string suff) {
        string dot = ".";
        // suffix + dot + prefix -> will look for all words that have the same suffix and prefix and return the max index
        return trie->search(suff + dot + pref);
    }
};