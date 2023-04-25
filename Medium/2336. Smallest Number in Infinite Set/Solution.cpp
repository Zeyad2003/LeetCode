class SmallestInfiniteSet {
public:
    set<int> st;
    int cur;
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        int val = *st.begin();
        if(!st.empty()) {
            st.erase(st.begin());
            return val;
        }
        cur++;
        return cur - 1;
    }

    void addBack(int num) {
        if(num < cur) st.insert(num);
    }
};