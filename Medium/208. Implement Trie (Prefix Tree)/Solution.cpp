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