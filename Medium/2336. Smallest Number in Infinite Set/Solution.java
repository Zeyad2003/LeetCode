import java.util.*;
class SmallestInfiniteSet {
    TreeSet<Integer> set;
    int cur;
    public SmallestInfiniteSet() {
        cur = 1;
        set = new TreeSet<>();
    }

    public int popSmallest() {
        if(!set.isEmpty()) {
            int val = set.first();
            set.remove(val);
            return val;
        }
        cur++;
        return cur - 1;
    }

    public void addBack(int num) {
        if(num < cur) set.add(num);
    }
}