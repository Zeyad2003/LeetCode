class Trie { // Trie data structure
private:
    bool isLeaf;
    unordered_map<char, Trie*> children;
public:
    Trie() : isLeaf(false) {};

    void insert(const string& word) {
        auto * cur = this;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end())
                cur->children[i]= new Trie();
            cur = cur->children[i];
        }
        cur->isLeaf = true;
    }

    string getWord(const string &word) {
        auto *cur = this;
        string ret;
        for(auto & i : word) {
            if(cur->children.find(i) == cur->children.end()) // not valid
                break; // return the original word
            ret.push_back(i);
            cur = cur->children[i];
            if(cur->isLeaf) return ret; // return the root of the word
        }
        return word;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie *trie = new Trie(); // Create a trie
        for(auto & i : dictionary) trie->insert(i); // Insert all the words in the trie
        stringstream ss(sentence); // Create a string stream
        string word, ans;
        while(ss >> word) // Get each word from the string stream
            ans += trie->getWord(word) + " "; // Get the root of the word and add it to the answer

        ans.pop_back(); // Remove the last space
        return ans; // Return the answer
    }
};